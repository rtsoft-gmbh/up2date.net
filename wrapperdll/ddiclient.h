#pragma once
#include <ddi.hpp>
#include <ritms_dps.hpp>

#include "CallbackDispatcher.hpp"
#include "dllexport.h"

namespace HkbClient {

    typedef bool (__stdcall *ProvErrorCallbackFunction)(const char* errorMessage);
	typedef bool (__stdcall *ProvSuccessCallbackFunction)(const char* up2DateEndpoint);

	static std::unique_ptr<Client> client;

	extern "C" {
		WDLL_EXPORT void AddConfigAttribute(ddi::ConfigResponseBuilder* responseBuilder, const char* key, const char* value);
		WDLL_EXPORT void DownloadArtifact(ddi::Artifact* artifact, const char* location);
		WDLL_EXPORT void RunClient(const char* clientCertificate, const char* provisioningEndpoint, const char* xApigToken,
			ProvErrorCallbackFunction provErrorAction,
			ProvSuccessCallbackFunction provSuccessAction,
			ConfigRequestCallbackFunction configRequest,
			DeploymentActionCallbackFunction deploymentAction,
			CancelActionCallbackFunction cancelAction,
			NoActionCallbackFunction noAction);
		WDLL_EXPORT void RunClientWithDeviceToken(const char* deviceToken, const char* hawkbitEndpoint,
			ConfigRequestCallbackFunction configRequest,
			DeploymentActionCallbackFunction deploymentAction,
			CancelActionCallbackFunction cancelAction,
			NoActionCallbackFunction noAction);
		WDLL_EXPORT void RunClientWithGatewayToken(const char* gatewayToken, const char* hawkbitEndpoint,
			ConfigRequestCallbackFunction configRequest,
			DeploymentActionCallbackFunction deploymentAction,
			CancelActionCallbackFunction cancelAction,
			NoActionCallbackFunction noAction);
		WDLL_EXPORT void StopClient();
		WDLL_EXPORT void RequestToPoll();
	}
}
