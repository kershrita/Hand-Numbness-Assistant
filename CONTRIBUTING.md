# Contributing to Hand Numbness Assistant

Thank you for your interest in contributing to the Hand Numbness Assistant project! This guide will help you get started with contributing to our assistive technology project.

## 📋 Table of Contents

- [Code of Conduct](#code-of-conduct)
- [Getting Started](#getting-started)
- [How to Contribute](#how-to-contribute)
- [Development Setup](#development-setup)
- [Coding Guidelines](#coding-guidelines)
- [Submitting Changes](#submitting-changes)
- [Reporting Issues](#reporting-issues)
- [Feature Requests](#feature-requests)

---

## 📜 Code of Conduct

By participating in this project, you agree to maintain a respectful and inclusive environment. Please:

- Be respectful and considerate of others
- Welcome newcomers and help them get started
- Focus on constructive feedback
- Accept that others may have different viewpoints

---

## 🚀 Getting Started

### Prerequisites

Before contributing, make sure you have:

1. **Arduino IDE** (version 1.8.x or 2.x) - [Download here](https://www.arduino.cc/en/software)
2. **Git** - [Download here](https://git-scm.com/downloads)
3. **Required Libraries** (see [README.md](README.md#software-dependencies))
4. **Hardware** (for testing): Arduino board, MLX90614 sensor, nRF24L01 modules

### Fork and Clone

1. Fork the repository on GitHub
2. Clone your fork locally:
   ```bash
   git clone https://github.com/YOUR_USERNAME/Hand-Numbness-Assistant.git
   cd Hand-Numbness-Assistant
   ```
3. Add the upstream remote:
   ```bash
   git remote add upstream https://github.com/kershrita/Hand-Numbness-Assistant.git
   ```

---

## 🤝 How to Contribute

### Types of Contributions

We welcome various types of contributions:

| Type | Description |
|------|-------------|
| 🐛 Bug Fixes | Fix issues in the existing code |
| ✨ Features | Add new functionality |
| 📝 Documentation | Improve or add documentation |
| 🖨️ 3D Parts | Improve or create new enclosure designs |
| 🧪 Testing | Test the hardware and report results |
| 🌍 Translations | Help translate documentation |

### Finding Things to Work On

- Check the [Issues](https://github.com/kershrita/Hand-Numbness-Assistant/issues) page
- Look for issues labeled `good first issue` for beginner-friendly tasks
- Look for issues labeled `help wanted` for areas needing assistance

---

## 💻 Development Setup

### Setting Up Arduino Development Environment

1. Install Arduino IDE
2. Install required libraries via Library Manager:
   - `RF24` by TMRh20
   - `DFRobot_MLX90614`

3. Extract and install libraries from `/libs`:
   - `Adafruit-GFX-Library-master.zip`
   - `Adafruit_SSD1306-master.zip`

### Project Structure

```
Hand-Numbness-Assistant/
├── transmitter/
│   └── transmitter.ino    # Temperature sensing code
├── receiver/
│   └── receiver.ino       # Alert receiving code
├── libs/
│   ├── Adafruit-GFX-Library-master.zip
│   └── Adafruit_SSD1306-master.zip
├── 3d parts/
│   ├── core-heat-box.stl
│   ├── core-heat-cover.stl
│   ├── core-pi-box.stl
│   └── core-pi-cover.stl
├── emissivity values table.xlsx
├── README.md
├── CONTRIBUTING.md
└── LICENSE
```

---

## 📐 Coding Guidelines

### Arduino Code Style

1. **Naming Conventions**:
   - Use `camelCase` for variables and functions
   - Use `UPPER_CASE` for constants and defines
   - Use descriptive names

2. **Comments**:
   - Add comments for complex logic
   - Include a brief description at the top of each file
   - Document function purposes

3. **Code Structure**:
   ```cpp
   // Include libraries
   #include <Library.h>
   
   // Define constants
   #define CONSTANT_NAME value
   
   // Global variables
   int variableName;
   
   void setup() {
       // Initialization code
   }
   
   void loop() {
       // Main logic
   }
   
   // Helper functions
   void helperFunction() {
       // Function code
   }
   ```

4. **Best Practices**:
   - Keep functions focused and small
   - Avoid magic numbers (use constants)
   - Test code before submitting

### 3D Model Guidelines

- Use metric units (millimeters)
- Design for FDM printing (no supports preferred)
- Include mounting holes for components
- Provide source files (if possible) alongside STL files

---

## 📤 Submitting Changes

### Creating a Pull Request

1. **Create a Branch**:
   ```bash
   git checkout -b feature/your-feature-name
   # or
   git checkout -b fix/issue-description
   ```

2. **Make Your Changes**:
   - Write clear, concise code
   - Test your changes with actual hardware
   - Update documentation if needed

3. **Commit Your Changes**:
   ```bash
   git add .
   git commit -m "Brief description of changes"
   ```
   
   Commit message format:
   - `feat:` for new features
   - `fix:` for bug fixes
   - `docs:` for documentation changes
   - `refactor:` for code refactoring
   - `test:` for adding tests

4. **Push to Your Fork**:
   ```bash
   git push origin feature/your-feature-name
   ```

5. **Create Pull Request**:
   - Go to the original repository on GitHub
   - Click "New Pull Request"
   - Select your branch
   - Fill in the PR template with:
     - Description of changes
     - Related issue (if any)
     - Testing performed
     - Screenshots (if applicable)

### Pull Request Review Process

1. Maintainers will review your PR
2. Address any requested changes
3. Once approved, your PR will be merged

---

## 🐛 Reporting Issues

### Before Creating an Issue

1. Search existing issues to avoid duplicates
2. Ensure you're using the latest version
3. Verify your hardware connections

### Creating an Issue

Include the following information:

1. **Description**: Clear description of the problem
2. **Steps to Reproduce**: How to recreate the issue
3. **Expected Behavior**: What should happen
4. **Actual Behavior**: What actually happens
5. **Hardware Setup**: Arduino model, sensor connections
6. **Software Version**: Arduino IDE version, library versions
7. **Serial Output**: Relevant serial monitor output
8. **Photos**: Pictures of your setup (if helpful)

### Issue Template

```markdown
## Description
[Clear description of the issue]

## Steps to Reproduce
1. [First step]
2. [Second step]
3. [...]

## Expected Behavior
[What should happen]

## Actual Behavior
[What actually happens]

## Environment
- Arduino Board: [e.g., Arduino Nano]
- Arduino IDE Version: [e.g., 2.0.0]
- RF24 Library Version: [e.g., 1.4.6]
- MLX90614 Library Version: [e.g., 1.0.0]

## Additional Information
[Any other relevant details]
```

---

## 💡 Feature Requests

We welcome ideas for improving the Hand Numbness Assistant!

### Suggesting a Feature

1. Check if the feature has already been requested
2. Create a new issue with the label `enhancement`
3. Include:
   - Clear description of the feature
   - Use case / problem it solves
   - Proposed implementation (if you have ideas)
   - Any relevant examples or references

### Feature Ideas We're Interested In

- Additional alert methods (visual displays, app notifications)
- Improved power management for longer battery life
- Temperature logging/history features
- Multiple temperature thresholds (hot/cold warnings)
- Improved 3D printed enclosure designs
- Mobile app companion

---

## 📞 Questions?

If you have questions about contributing:

1. Check the [README.md](README.md) for project information
2. Look through existing issues and discussions
3. Create a new issue with the `question` label

---

Thank you for helping make assistive technology more accessible! 🙏
