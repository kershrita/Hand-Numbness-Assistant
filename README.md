# Hand Numbness Assistant 🖐️🌡️

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Arduino](https://img.shields.io/badge/Platform-Arduino-00979D.svg)](https://www.arduino.cc/)
[![Contributions Welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg)](CONTRIBUTING.md)

An assistive wearable device designed to help people with hand numbness safely interact with their environment by detecting object temperatures before physical contact.

---

## Table of Contents

- [Overview](#overview)
- [Problem Statement](#problem-statement)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Dependencies](#software-dependencies)
- [System Architecture](#system-architecture)
- [Circuit Connections](#circuit-connections)
- [Installation](#installation)
- [Usage](#usage)
- [3D Printed Parts](#3d-printed-parts)
- [Configuration](#configuration)
- [Troubleshooting](#troubleshooting)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

---

## Overview

The Hand Numbness Assistant is an Arduino-based wearable system that uses the **MLX90614 Non-Contact IR Temperature Sensor** to detect object temperatures without physical contact. This device helps individuals who suffer from conditions like peripheral neuropathy, diabetes-related numbness, or other sensory impairments by alerting them when an object is too hot or cold to safely touch.

---

## Problem Statement

People with hand numbness face a significant daily challenge: they cannot feel temperature differences through touch. This puts them at risk of:

- **Burns** from hot surfaces, liquids, or objects
- **Frostbite** from extremely cold items
- **Injuries** from unknowingly handling dangerous temperature objects

This project provides a practical, affordable solution by offering **pre-contact temperature sensing** with real-time alerts.

---

## Features

- **Non-Contact Temperature Sensing**: Measures object temperature without touching it
- **Wireless Communication**: Uses nRF24L01 radio modules for transmitter-receiver communication
- **Real-time Alerts**: Audible buzzer and LED indicators for temperature warnings
- **Wearable Vibration Alert**: Receiver unit can be worn on the wrist for haptic feedback
- **Configurable Threshold**: Adjustable temperature threshold (default: 40°C)
- **Emissivity Correction**: Accurate readings across different material types
- **Low Power Consumption**: Suitable for portable, battery-powered operation
- **3D Printable Enclosure**: Custom-designed cases for easy assembly

---

## Hardware Requirements

### Transmitter Unit (Temperature Sensing Module)

| Component | Quantity | Description |
|-----------|----------|-------------|
| Arduino Nano/Uno | 1 | Main microcontroller |
| MLX90614 | 1 | Non-contact IR temperature sensor |
| nRF24L01 | 1 | 2.4GHz wireless transceiver module |
| Buzzer | 1 | Audio alert indicator |
| Red LED | 1 | Visual warning indicator |
| 220Ω Resistor | 1 | LED current limiting |
| Capacitor 10µF | 1 | nRF24L01 power stabilization |
| Wires | - | Jumper wires for connections |
| Power Supply | 1 | 5V battery pack or USB power |

### Receiver Unit (Wearable Alert Module)

| Component | Quantity | Description |
|-----------|----------|-------------|
| Arduino Nano/Uno | 1 | Main microcontroller |
| nRF24L01 | 1 | 2.4GHz wireless transceiver module |
| Vibration Motor | 1 | Haptic feedback alert |
| Capacitor 10µF | 1 | nRF24L01 power stabilization |
| Wires | - | Jumper wires for connections |
| Power Supply | 1 | 3.7V LiPo battery or USB power |

---

## Software Dependencies

### Arduino Libraries Required

1. **RF24** - For nRF24L01 wireless communication
   - Install via Arduino Library Manager: `RF24 by TMRh20`

2. **DFRobot_MLX90614** - For MLX90614 temperature sensor
   - Install via Arduino Library Manager or [DFRobot GitHub](https://github.com/DFRobot/DFRobot_MLX90614)

3. **Adafruit GFX Library** - Graphics library (included in `/libs`)

4. **Adafruit SSD1306** - OLED display support (included in `/libs`)

5. **SPI** - Built-in Arduino library

---

## System Architecture

```
┌─────────────────────────────────────────────────────────────────┐
│                    TRANSMITTER UNIT                             │
│  ┌─────────────┐    ┌─────────────┐    ┌─────────────┐         │
│  │  MLX90614   │───▶│   Arduino   │───▶│  nRF24L01   │────┐    │
│  │ Temp Sensor │    │   Nano/Uno  │    │   Radio     │    │    │
│  └─────────────┘    └──────┬──────┘    └─────────────┘    │    │
│                            │                               │    │
│                     ┌──────┴──────┐                        │    │
│                     │ Buzzer + LED│                        │    │
│                     └─────────────┘                        │    │
└────────────────────────────────────────────────────────────┼────┘
                                                             │
                         Wireless Communication (2.4GHz)     │
                                                             │
┌────────────────────────────────────────────────────────────┼────┐
│                     RECEIVER UNIT                          │    │
│  ┌─────────────┐    ┌─────────────┐    ┌─────────────┐    │    │
│  │  Vibration  │◀───│   Arduino   │◀───│  nRF24L01   │◀───┘    │
│  │    Motor    │    │   Nano/Uno  │    │   Radio     │         │
│  └─────────────┘    └─────────────┘    └─────────────┘         │
└─────────────────────────────────────────────────────────────────┘
```

---

## Circuit Connections

### Transmitter Unit Wiring

#### MLX90614 to Arduino
| MLX90614 Pin | Arduino Pin |
|--------------|-------------|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

#### nRF24L01 to Arduino
| nRF24L01 Pin | Arduino Pin |
|--------------|-------------|
| VCC | 3.3V |
| GND | GND |
| CE | D10 |
| CSN | D9 |
| SCK | D13 |
| MOSI | D11 |
| MISO | D12 |

#### Alert Components
| Component | Arduino Pin |
|-----------|-------------|
| Buzzer (+) / LED Anode | D2 (wired in parallel, LED via 220Ω resistor) |

> **Note**: The buzzer and LED share the same output pin (D2) and are wired in parallel. This allows both alert mechanisms to activate simultaneously when the temperature threshold is exceeded.

### Receiver Unit Wiring

#### nRF24L01 to Arduino
| nRF24L01 Pin | Arduino Pin |
|--------------|-------------|
| VCC | 3.3V |
| GND | GND |
| CE | D10 |
| CSN | D9 |
| SCK | D13 |
| MOSI | D11 |
| MISO | D12 |

#### Vibration Motor
| Component | Arduino Pin |
|-----------|-------------|
| Vibration Motor (+) | D2 |

> **Note**: Add a 10µF capacitor between VCC and GND of nRF24L01 for power stability.

---

## Installation

### Step 1: Install Arduino IDE

Download and install the [Arduino IDE](https://www.arduino.cc/en/software) (version 1.8.x or 2.x).

### Step 2: Install Required Libraries

1. Open Arduino IDE
2. Go to **Sketch** → **Include Library** → **Manage Libraries**
3. Search and install:
   - `RF24` by TMRh20
   - `DFRobot_MLX90614`

4. For the included libraries in `/libs`:
   - Extract `Adafruit-GFX-Library-master.zip`
   - Extract `Adafruit_SSD1306-master.zip`
   - Copy to your Arduino libraries folder (typically `Documents/Arduino/libraries/`)

### Step 3: Clone the Repository

```bash
git clone https://github.com/kershrita/Hand-Numbness-Assistant.git
cd Hand-Numbness-Assistant
```

### Step 4: Upload Transmitter Code

1. Open `transmitter/transmitter.ino` in Arduino IDE
2. Select your board: **Tools** → **Board** → **Arduino Nano/Uno**
3. Select the correct COM port
4. Click **Upload**

### Step 5: Upload Receiver Code

1. Open `receiver/receiver.ino` in Arduino IDE
2. Select your board: **Tools** → **Board** → **Arduino Nano/Uno**
3. Select the correct COM port
4. Click **Upload**

---

## Usage

1. **Power On**: Connect both transmitter and receiver units to their power sources.

2. **Initial Connection**: Wait for the serial monitor to display "Connected!" (receiver) and confirm the sensor is initialized (transmitter).

3. **Point and Measure**: 
   - Point the transmitter unit's sensor toward the object you want to measure
   - Hold at a distance of 2-5 cm for optimal accuracy

4. **Alert Interpretation**:
   - **No alert**: Object temperature is below the threshold (safe to touch)
   - **Buzzer + LED + Vibration**: Object temperature exceeds the threshold (DANGER - do not touch!)

5. **Serial Monitor**: Connect to the transmitter via USB to view real-time temperature readings:
   ```
   Ambient celsius : 24.5 C
   Object celsius : 65.3 C
   ```

---

## 3D Printed Parts

Custom enclosures are provided in the `3d parts/` directory:

| File | Description |
|------|-------------|
| `core-heat-box.stl` | Transmitter unit main body |
| `core-heat-cover.stl` | Transmitter unit cover |
| `core-pi-box.stl` | Receiver unit main body |
| `core-pi-cover.stl` | Receiver unit cover |

### Print Settings (Recommended)

- **Material**: PLA or PETG
- **Layer Height**: 0.2mm
- **Infill**: 20%
- **Supports**: Not required

---

## Configuration

### Adjusting Temperature Threshold

Edit the threshold value in `transmitter/transmitter.ino`:

```cpp
#define TEMPERATURE_THRESHOLD 40.0  // Change this value (in Celsius)
```

### Emissivity Correction

Different materials have different emissivity values. Adjust in `transmitter/transmitter.ino`:

```cpp
sensor.setEmissivityCorrectionCoefficient(0.98);  // Default value
```

Refer to `emissivity values table.xlsx` for common material emissivity values.

| Material | Emissivity |
|----------|------------|
| Human Skin | 0.98 |
| Water | 0.96 |
| Metal (polished) | 0.05-0.10 |
| Plastic | 0.85-0.95 |
| Wood | 0.80-0.90 |

---

## Troubleshooting

### Common Issues and Solutions

| Issue | Possible Cause | Solution |
|-------|----------------|----------|
| "Not Connected!" message | Radio not properly connected | Check nRF24L01 wiring and add 10µF capacitor |
| No temperature readings | Sensor connection issue | Verify MLX90614 I2C connections (SDA/SCL) |
| Inaccurate readings | Wrong emissivity value | Adjust emissivity for the material being measured |
| No wireless communication | Address mismatch | Ensure both units use the same address (`"12345"`) |
| Receiver not vibrating | Motor connection issue | Check pin D2 connection and motor polarity |

### Serial Monitor Debugging

1. Open Arduino IDE Serial Monitor (9600 baud)
2. Monitor transmitter output for temperature readings
3. Monitor receiver output for received signals (`true`/`false`)

---

## Contributing

Contributions are welcome! Please read our [Contributing Guidelines](CONTRIBUTING.md) before submitting a pull request.

### Ways to Contribute

- Report bugs and issues
- Suggest new features
- Improve documentation
- Submit code improvements
- Share improved 3D print designs

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## Contact

**Ashraf Abdulkhaliq**

- GitHub: [@kershrita](https://github.com/kershrita)

---

<p align="center">
  Made with ❤️ for accessibility and assistive technology
</p>
