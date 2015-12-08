#include "CddApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "Factory.h"

#include "SimpleConvection.h"
#include "BoundingBoxFuncIC.h"
#include "ParamReaction.h"
#include "CoupledReaction.h"
#include "CoupledReactionP3.h"
#include "CoupledReactionNoU.h"

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
//  ModulesApp::registerObjects(_factory);
  CddApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
//  ModulesApp::associateSyntax(_syntax, _action_factory);
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
  // Register any custom objects you have built on the MOOSE Framework
  registerKernel(SimpleConvection);  // <- registration
  registerInitialCondition(BoundingBoxFuncIC);
  registerKernel(ParamReaction);
  registerKernel(CoupledReaction);
  registerKernel(CoupledReactionP3);
  registerKernel(CoupledReactionNoU);
}

// External entry point for dynamic syntax association
extern "C" void CddApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { CddApp::associateSyntax(syntax, action_factory); }
void
CddApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
