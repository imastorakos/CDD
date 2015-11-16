#ifndef CDDAPP_H
#define CDDAPP_H

#include "MooseApp.h"

class CddApp;

template<>
InputParameters validParams<CddApp>();

class CddApp : public MooseApp
{
public:
  CddApp(InputParameters parameters);
  virtual ~CddApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* CDDAPP_H */
