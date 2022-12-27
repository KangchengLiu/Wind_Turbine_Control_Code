<!--
SPDX-FileCopyrightText: 2022 Contributors to the Power Grid Model project <dynamic.grid.calculation@alliander.com>

SPDX-License-Identifier: MPL-2.0
-->
[![PyPI version](https://badge.fury.io/py/power-grid-model.svg)](https://badge.fury.io/py/power-grid-model)
[![License: MIT](https://img.shields.io/badge/License-MPL2.0-informational.svg)](https://github.com/alliander-opensource/power-grid-model/blob/main/LICENSE)
[![Build and Test C++ and Python](https://github.com/alliander-opensource/power-grid-model/actions/workflows/main.yml/badge.svg)](https://github.com/alliander-opensource/power-grid-model/actions/workflows/main.yml)
[![Check Code Quality](https://github.com/alliander-opensource/power-grid-model/actions/workflows/check-code-quality.yml/badge.svg)](https://github.com/alliander-opensource/power-grid-model/actions/workflows/check-code-quality.yml)
[![REUSE Compliance Check](https://github.com/alliander-opensource/power-grid-model/actions/workflows/reuse-compliance.yml/badge.svg)](https://github.com/alliander-opensource/power-grid-model/actions/workflows/reuse-compliance.yml)
[![docs](https://readthedocs.org/projects/power-grid-model/badge/)](https://power-grid-model.readthedocs.io/en/stable/)

[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=alliander-opensource_power-grid-model&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=alliander-opensource_power-grid-model)
[![Coverage](https://sonarcloud.io/api/project_badges/measure?project=alliander-opensource_power-grid-model&metric=coverage)](https://sonarcloud.io/summary/new_code?id=alliander-opensource_power-grid-model)
[![Maintainability Rating](https://sonarcloud.io/api/project_badges/measure?project=alliander-opensource_power-grid-model&metric=sqale_rating)](https://sonarcloud.io/summary/new_code?id=alliander-opensource_power-grid-model)
[![Reliability Rating](https://sonarcloud.io/api/project_badges/measure?project=alliander-opensource_power-grid-model&metric=reliability_rating)](https://sonarcloud.io/summary/new_code?id=alliander-opensource_power-grid-model)
[![Security Rating](https://sonarcloud.io/api/project_badges/measure?project=alliander-opensource_power-grid-model&metric=security_rating)](https://sonarcloud.io/summary/new_code?id=alliander-opensource_power-grid-model)
[![Vulnerabilities](https://sonarcloud.io/api/project_badges/measure?project=alliander-opensource_power-grid-model&metric=vulnerabilities)](https://sonarcloud.io/summary/new_code?id=alliander-opensource_power-grid-model)

<img src="docs\images\pgm-logo-color.svg" alt="Power Grid Model logo" width="100"/>

# Power Grid Model

`power-grid-model` is a Python library for steady-state distribution power system analysis.
The core of the library is written in C++.
Currently, it supports the following calculations:

* Symmetric and asymmetric power flow calculation with Newton-Raphson method, iterative current method and linear method
* Symmetric and asymmetric state estimation with iterative linear method

See the [power-grid-model documentation](https://power-grid-model.readthedocs.io/en/stable/) for more information.
For various conversions to the power-grid-model, refer to the [power-grid-model-io](https://github.com/alliander-opensource/power-grid-model-io) repository.

# Installation

## Install from PyPI

You can directly install the package from PyPI.

```
pip install power-grid-model
```

## Build and install from Source

To install the library from source, refer to the [Build Guide](docs/advanced_documentation/build-guide.md).

# Examples

Please refer to [Examples](docs/examples) for more detailed examples for power flow and state estimation. 
Notebooks for validating the input data and exporting input/output data are also included.


