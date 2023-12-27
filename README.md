# Arcane #

Write something about the engine in here in the future.

## Getting Started ##

If you want to explore or contribute to any of these projects, follow these steps:

1. Clone the repository:

    ```bash
    git clone https://github.com/Arcane-Studios/Arcane.git --recursive
    ```

2. Open the Arcane directory and Run `GenerateProjects.bat` from the [Build](Build) directory.

## Contributing ##

If you'd like to contribute to any of the projects, feel free to open an issue or submit a pull request. Contributions, suggestions, and feedback are always welcome!

- To add new features create a branch:
  > developer_name/feature_name
  > 
- Method signature
  > int MyFunctionSignatureInCamelCase(Arguments args);
  
- Member variables prefixed with m_ and static variables prefixed with s_ ( no prefix for structs members )
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
- Platform specific code goes behind _#ifdef_ block with  _#error_ on _#else_ statement

## License ##

This repository is licensed under the [GPL-3.0 License](LICENSE). See the [LICENSE](LICENSE) file for details.

### Contributors 
- Ishan Chaudhari (_TheSpectreZ_)
- Matheus Marchetti (_matheusbr16_)
- Nicholas (_Vorawwgo_)
- (_AutoPilot2004_)
---
