﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
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

#include <aws/pinpoint-email/model/GetBlacklistReportsRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::PinpointEmail::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

GetBlacklistReportsRequest::GetBlacklistReportsRequest() : 
    m_blacklistItemNamesHasBeenSet(false)
{
}

Aws::String GetBlacklistReportsRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_blacklistItemNamesHasBeenSet)
  {
   Array<JsonValue> blacklistItemNamesJsonList(m_blacklistItemNames.size());
   for(unsigned blacklistItemNamesIndex = 0; blacklistItemNamesIndex < blacklistItemNamesJsonList.GetLength(); ++blacklistItemNamesIndex)
   {
     blacklistItemNamesJsonList[blacklistItemNamesIndex].AsString(m_blacklistItemNames[blacklistItemNamesIndex]);
   }
   payload.WithArray("BlacklistItemNames", std::move(blacklistItemNamesJsonList));

  }

  return payload.View().WriteReadable();
}

Aws::Http::HeaderValueCollection GetBlacklistReportsRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  headers.insert(Aws::Http::HeaderValuePair("X-Amz-Target", "com.amazonaws.services.pinpoint.email.GetBlacklistReports"));
  return headers;

}




