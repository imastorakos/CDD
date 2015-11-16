#include "CddApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<CddApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

CddApp::CddApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  CddApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  CddApp::associateSyntax(_syntax, _action_factory);
}

CddApp::~CddApp()
{
}

// External entry point for dynamic application loading
extern "C" void CddApp__registerApps() { CddApp::registerApps(); }
void
CddApp::registerApps()
{
  registerApp(CddApp);
}

// External entry point for dynamic object registration
extern "C" void CddApp__registerObjects(Factory & factory) { CddApp::registerObjects(factory); }
void
CddApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void CddApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { CddApp::associateSyntax(syntax, action_factory); }
void
CddApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
