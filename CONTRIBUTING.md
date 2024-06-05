# Contributing Guidelines

Thank you for contributing to this project! To maintain a high standard of quality, we use conventional commit conventions. This document will guide you through the best practices for commits and branch management.

## Table of Contents

1. [Commit Conventions](#commit-conventions)
2. [Branch Naming](#branch-naming)
3. [Naming conventions](#naming-conventions)
4. [Doxygen](#doxygen)
5. [Includes](#includes)

## Commit Conventions

We use the [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/) commit conventions. This ensures a clear and meaningful commit history. [Other useful link](https://gist.github.com/qoomon/5dfcdf8eec66a051ecd85625518cfd13#file-conventional_commit_messages-md)

## Branch Naming

To maintain an organized repository, we have naming conventions for branches. Here are the branch types and their formats:

- **feature** : For new features -> `feat/<short description>`
- **bugfix** : For bug fixes -> `bugfix/<short description>`
- **hotfix** : For urgent fixes -> `hotfix/<short description>`
- **refactor** : For refactoring -> `refactor/<version>`
- **documentation** : For adding or updating documentation -> `doc/<short description>`

Please adhere to these conventions to facilitate collaboration and project maintenance. Happy coding!

## Naming conventions

We follow a mix between the [Epitech coding-style](https://github.com/ronanboiteau/NormEZ/blob/master/epitech_coding_styles_pdf/epitech_c_coding_style.pdf) and our in-house coding style.

- In C : snake_case (Epitech)
- In C++ : 
    - variables = camelCase
    - classes = PascalCase
    - functions = camelCase
    - constants = ALL_CAPS
    - macros = ALL_CAPS
    - namespaces = PascalCase
    - enums = camelCase
    - structs = snake_case
    - files & folders = PascalCase
    - root folders = snake_case
- In Python : Same as our C++ conventions

## Doxygen
We use [doxygen](https://www.doxygen.nl/manual/docblocks.html) to document our code. 
Some keys:
- If it is a sentence, always start with an uppercase and end comment with a dot.
- For classes variables, comment right after //.

## Includes
- Always include the necessary headers ONLY.
- Always include the headers in the following order:
    - Project headers
    - Standard library headers
