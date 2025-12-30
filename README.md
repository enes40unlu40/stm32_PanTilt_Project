# stm32_PanTilt_Project
> Modular Embedded System – Step-by-Step Tutorial

This repository presents a **modular embedded system** designed and documented as a **tutorial-style project**.  
The goal is to explain not only *what the system does*, but also *how and why each subsystem is designed*, enabling easy extension and reuse.

---

## 1. System Overview

This system is a simple and fundemental architecture for school and individual projects. The system is Pan-Tilt system that includes most of the embedded features; Interrupt, PWM, Timers, ADC+DMA Integration and I2C Communication(LCD Control). The system is structured into clearly separated functional layers:

This separation ensures:
- High readability and maintainability
- Independent development and testing of modules
- Easy scalability for future features

---

## 2. Hardware Architecture

### 2.1 Microcontroller Unit (MCU)
- **MCU Family:** STM32
- **Core:** ARM Cortex-M
- **Clock Configuration:** Internal / External oscillator
- **Power Modes:** Run, Sleep, Stop

The MCU acts as the central processing and coordination unit, handling timing, control logic, and peripheral communication.

---

### 2.2 Input Modules

Input modules are responsible for acquiring data from the physical environment.

#### 2.2.1 Analog Inputs
- ADC-based data acquisition
- Single or multi-channel scan mode
- DMA-supported continuous sampling

**Typical use cases:**
- Potentiometers
- Light sensors (LDR)
- Analog environmental sensors

---

#### 2.2.2 Digital Inputs
- GPIO-based inputs
- External interrupts (EXTI)
- Configurable pull-up / pull-down resistors

**Typical use cases:**
- Push buttons
- Limit switches
- Digital sensors

---

### 2.3 Output Modules

#### 2.3.1 PWM Outputs
- Timer-based PWM generation
- Configurable frequency and duty cycle

**Typical use cases:**
- Servo motor control
- DC motor speed control
- LED brightness control

---

#### 2.3.2 Digital Outputs
- GPIO output pins
- Event-driven or state-based control

**Typical use cases:**
- Relays
- Status LEDs
- Enable/disable signals

---

## 3. Software Architecture

The software follows a **layered and modular architecture**.

### 3.1 Core Layer
- System startup and initialization
- Clock and basic peripheral configuration
- Main execution loop

This layer forms the backbone of the system.

---

### 3.2 Driver Layer
- HAL / LL drivers
- Direct hardware abstraction

Includes configuration for:
- GPIO
- ADC
- Timers
- Communication peripherals (I2C, UART, CAN, SPI)

---

### 3.3 Middleware / Logic Layer

This layer contains the system’s core intelligence.

Typical responsibilities:
- Raw ADC data conversion to physical values
- Signal filtering
- State machines
- Control algorithms (e.g., PID)

---

### 3.4 Application Layer

Defines **system behavior and use cases**.

Examples:
- Mapping joystick input to actuator angles
- Sensor-driven decision making
- User interaction logic

---

## 4. Timing and Scheduling

The system timing is handled using:
- Hardware timers
- Interrupt service routines

Goals:
- Deterministic execution
- Low-latency response
- Reliable real-time behavior

---

## 5. Power Management

Supported power-saving strategies:
- Sleep mode operation
- Interrupt-based wake-up
- Peripheral clock gating

These techniques improve energy efficiency and system longevity.

---

## 6. Communication Interfaces

The architecture supports modular communication interfaces:

- UART (debugging and logging)
- I2C (displays and sensors)
- SPI
- CAN (industrial expansion)

Each interface is implemented as an independent module.

---

## 8. Extending the System

To add a new feature:
1. Identify the appropriate layer
2. Implement the module 
3. Integrate it with the core system
4. Test and document the functionality

This approach prevents tight coupling and encourages clean system growth.

---

## 9. Known Limitations
- [Current hardware or software limitation]
- [Unimplemented feature]

---

## 10. Future Improvements
- [ ] Additional sensor integration
- [ ] Advanced control algorithms
- [ ] RTOS-based task management

---

## 11. Author
- **Author : Enes ÜNLÜ:**  
- **Contact: enesunlu40@outlook.com.tr**
  (Feel free to ask question or to talk for improvements by my e-mail address)
---

## 12. License
This project is released under the no license so anybody can use, copy this project.


