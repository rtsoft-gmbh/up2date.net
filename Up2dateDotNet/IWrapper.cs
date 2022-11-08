﻿using System;

namespace Up2dateDotNet
{
    public delegate void ConfigRequestFunc(IntPtr responseBuilder);
    public delegate void DeploymentActionFunc(IntPtr artifact, DeploymentInfo info, out ClientResult result);
    public delegate bool CancelActionFunc(int stopId);
    public delegate void AuthErrorActionFunc(string errorMessage);

    public interface IWrapper
    {
        IntPtr CreateDispatcher(ConfigRequestFunc onConfigRequest, DeploymentActionFunc onDeploymentAction, CancelActionFunc onCancelAction);

        void DeleteDispatcher(IntPtr dispatcher);

        void DownloadArtifact(IntPtr artifact, string location);

        void AddConfigAttribute(IntPtr responseBuilder, string key, string value);

        void RunClient(string clientCertificate, string provisioningEndpoint, string xApigToken, IntPtr dispatcher, AuthErrorActionFunc onAuthErrorAction);

        void RunClientWithDeviceToken(string deviceToken, string hawkbitEndpoint, string controllerId, string tenant, IntPtr dispatcher);

        void RunClientWithGatewayToken(string gatewayToken, string hawkbitEndpoint, string controllerId, string tenant, IntPtr dispatcher);
    }
}