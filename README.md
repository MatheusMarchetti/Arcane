# Arcane

Write something about the engine in here in the future

### Tech stack

- C++ 20 for engine
- C# for scripting
- Premake for build system

### Contributing

- To add new features create a branch:
  > developer_name/feature_name
  > 
- Method signature
  > int MyFunctionSignatureInCamelCase(Arguments args);
  
- Member variables prefixed with m_ and static variables prefixed with s_
- Necessary 3rd-party libraries added as git submodules
- STL containers wrapped in utl namespace
  > namespace utl
  > 
  > {
  > 
  >  template<typename T>
  >
  >  using vector = std::vector<T>
  >
  > }
- Constants are _CAPITALIZED_
- Platform specific code goes behing _#ifdef_ block with  _#pragma error_ on _#else_ statement

### Contributors (in alphabetical order)
- Ishan Chaudhari (_TheSpectreZ_)
- Matheus Marchetti (_matheusbr16_)
- Nicholas (_Vorawwgo_)
