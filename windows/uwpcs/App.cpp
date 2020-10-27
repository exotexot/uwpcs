#include "pch.h"

#include "App.h"

#include "AutolinkedNativeModules.g.h"
#include "ReactPackageProvider.h"


using namespace winrt::uwpcs;
using namespace winrt::uwpcs::implementation;

/// <summary>
/// Initializes the singleton application object.  This is the first line of
/// authored code executed, and as such is the logical equivalent of main() or
/// WinMain().
/// </summary>
App::App() noexcept
{
    MainComponentName(L"uwpcs");

#if BUNDLE
    JavaScriptBundleFile(L"index");
    InstanceSettings().UseWebDebugger(true);
    InstanceSettings().UseFastRefresh(true);
#else
    JavaScriptMainModuleName(L"index");
    InstanceSettings().UseWebDebugger(false);
    InstanceSettings().UseFastRefresh(true);
#endif

#if _DEBUG
    InstanceSettings().EnableDeveloperMenu(true);
#else
    InstanceSettings().EnableDeveloperMenu(true);
#endif

    RegisterAutolinkedNativeModulePackages(PackageProviders()); // Includes any autolinked modules

    PackageProviders().Append(make<ReactPackageProvider>()); // Includes all modules in this project

    PackageProviders().Append(winrt::RNDeviceInfo::ReactPackageProvider());

    InitializeComponent();
}
