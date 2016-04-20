/*
  * Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
  * 
  * Licensed under the Apache License, Version 2.0 (the "License").
  * You may not use this file except in compliance with the License.
  * A copy of the License is located at
  * 
  *  http://aws.amazon.com/apache2.0
  * 
  * or in the "license" file accompanying this file. This file is distributed
  * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
  * express or implied. See the License for the specific language governing
  * permissions and limitations under the License.
  */

#include <aws/external/gtest.h>
#include <aws/core/utils/crypto/Cipher.h>

int main(int argc, char** argv)
{
    #ifndef _WIN32
        //Set $HOME to tmp on unix systems
        setenv("HOME", P_tmpdir, 1);
    #endif //__UNIX_SV__

    Aws::Utils::Crypto::InitCiphers();
    ::testing::InitGoogleTest(&argc, argv);
    int retVal = RUN_ALL_TESTS();
    Aws::Utils::Crypto::CleanupCiphers();
    return retVal;
}
