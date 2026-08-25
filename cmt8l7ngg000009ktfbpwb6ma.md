---
title: "From 8051 to STM32: My Next Chapter in Embedded Systems
"
datePublished: 2026-08-25T11:34:16.220Z
cuid: cmt8l7ngg000009ktfbpwb6ma
slug: from-8051-to-stm32-my-next-chapter-in-embedded-systems
cover: https://cdn.hashnode.com/uploads/covers/6a2649aba310674fdac6fca6/13872cc8-f58d-4134-948b-f51c10f057a2.png

---

Not really of course. 😄

But after spending months learning **Jarvis Building Journey** I noticed something has changed.

Jarvis has been my way of learning the C programming concepts, developing my problem solving skills and eventually getting into embedded systems. I had started from a very humble beginning figuring out small simple concepts - Calculators, loops, arrays, function and slowly moved on to a bigger project that was combination of all these small concepts - Library management, student attendance system. This experience taught me how to think to find the solution. It was not just making the program work; but it was about learning how to think.

Then came 8051.

From there Jarvis stepped out of the terminal and started getting a body.

### Jarvis Gets a Body

When I started learning **8051 microcontroller** I actually came to know how a code interacts with hardware, embedded systems became real.

Until then, most of my C programs were limited to the terminal.

Now I was writing code that could actually control hardware.

I worked with **Keil uVision and Proteus**, and experimented with basic GPIO concepts through LED blinking, sourcing, and sinking. Something as simple as making an LED turn on and off suddenly felt different when I realized that the code I had written was controlling an actual electronic system.

That was an important transition in my learning journey.

I wasn't just learning C anymore.

I was learning **Embedded C**.

### But Jarvis had reached its Limit.

The 8051 gave me my first real understanding of microcontrollers, but i wanted to go deeper.

I wanted to work with:

*   `More GPIO capabilities`
    
*   `Timers`
    
*   `UART`
    
*   `PWM`
    
*   `ADC`
    
*   `SPI`
    
*   `I2C`
    
*   `Interrupts`
    
*   `More powerful peripherals`
    
*   `Register-level hardware control`
    

And that's when I decided it was a time for an upgrade.

If Jarvis was my first embedded chapter...

**Ultron had arrived.**

And I needed something new.

## Meet FRIDAY

So I started my new chapter transitioning from 8051 to STM32:

### FRIDAY

The next step was choosing a development board with an entry level microcontroller so I chose **STM32F103C8,** which is found on the small development board also called as **Blue-Pill**.

This isn't just another microcontroller for me.

It's my opportunity to take everything I've learned about C and start applying it to a more capable microcontroller platform.

The workflow itself is already different.

Instead of just writing C and simulating it in Proteus, I'm now working with:

**STM32CubeMX → STM32CubeIDE → ST-Link → Blue Pill**

CubeMX handles the hardware configuration and can generate the initialization code, while CubeIDE provides the environment for writing, building, debugging, and flashing the C firmware.

And the most important part?

**The language hasn't changed.**

It's still C.

The `if`, `while`, functions, variables, arrays, pointers, structures, and all the logic I've been learning are still there.

What's changing is what that C code can control.

### My First Experiments with STM32.

I decided not to jump directly into complex peripherals.

Instead, I started with the fundamentals:

**GPIO configuration, register manipulation, LED patterns, button input, and timing.**

Rather than relying entirely on HAL functions, I wanted to understand how the STM32's registers are configured directly.

My first experiments involved controlling **PC13, PC14, and PC15** while using **PB12 as a button input**.

### Experiment 1 — LED Pattern Controlled by a Button

For the first experiment, I configured:

*   **PC13, PC14, PC15** as GPIO outputs
    
*   **PB12** as a GPIO input
    
*   PB12 was configured with an internal pull-up
    
*   The button was used to change the LED pattern
    
*   GPIO registers such as `CRH`, `IDR`, `BSRR`, `BRR`, and `ODR` were accessed directly
    
*   A simple software delay was implemented using `__NOP()`
    

The interesting part for me wasn't just making the LEDs blink.

It was understanding **why each register was being modified**.

For example:

```c
RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
```

Before configuring the GPIO pins, I first had to enable the clocks for GPIOC and GPIOB.

Then I configured the GPIO modes directly through the configuration registers:

```c
GPIOC->CRH &= ~(0xFU << 20);
GPIOC->CRH |=  (0x2U << 20);
```

This was a very different experience from simply calling a GPIO initialization function.

I was now looking at the register and asking:

> **Which bits correspond to my pin, and what value should those bits contain?**

### LED Pattern

I then used the `BSRR` and `BRR` registers to control the LEDs and created different patterns depending on the state of PB12.

For example, one sequence turned on `PC13` while keeping `PC14` and `PC15` off, followed by another combination:

```c
GPIOC->BSRR = (1U << 13);
GPIOC->BRR  = (1U << 14);
GPIOC->BRR  = (1U << 15);

delay(1);

GPIOC->BSRR = (1U << 13);
GPIOC->BSRR = (1U << 14);
GPIOC->BRR  = (1U << 15);
```

The button state was read directly from the input data register:

```c
if(!(GPIOB->IDR & (1U << 12)))
{
    // LED pattern
}
```

This was my first real experience of using a **microcontroller register as the interface between my C code and the physical hardware**.

## Experiment 2 — Button-Controlled LED

After experimenting with multiple LEDs, I simplified the problem.

This time I configured **PC14 as an input** and **PC15 as an output**.

The basic idea was:

```plaintext
Button pressed
      ↓
Read PC14
      ↓
PC15 LED ON
```

And when the button wasn't pressed:

```plaintext
Button released
      ↓
Read PC14
      ↓
PC15 LED OFF
```

The important part was again the direct register access:

```c
if(!(GPIOC->IDR & (1U << 14)))
{
    GPIOC->BSRR |= (1U << 15);

    while(!(GPIOC->IDR & (1U << 14)));
}
else
{
    GPIOC->BRR = (1U << 15);
}
```

I also used a `while` loop to wait for the button state to change.

This small experiment helped me understand something fundamental about embedded programming:

> **The microcontroller isn't waiting for an event in the way a desktop program might. It can continuously monitor a hardware input and make decisions based on its current state.**

## Why I Started With Registers

I could have written these experiments using HAL functions.

But for now, I deliberately chose not to.

I wanted to understand the layer underneath the abstraction.

When I write:

```c
GPIOC->BSRR = (1U << 15);
```

I want to know:

*   What is `GPIOC`?
    
*   What is `BSRR`?
    
*   Why is bit 15 being shifted?
    
*   What happens inside the GPIO peripheral?
    
*   Why use `BSRR` instead of `ODR`?
    
*   What does `BRR` actually do?
    

These questions are becoming more important to me than simply getting the LED to turn on.

Because eventually, I don't want to say:

> **"I know how to use STM32."**

I want to be able to say:

> **"I understand how STM32 works."**

## From Simple LEDs to Firmware

These experiments may look extremely basic.

Three LEDs.

One button.

A few registers.

A software delay.

But for me, this is the foundation of FRIDAY.

The progression I'm following is intentional:

```c
C Programming
      ↓
    8051
      ↓
    STM32
      ↓
GPIO Registers
      ↓
    Timers
      ↓
    Interrupts
      ↓
Communication Protocols
      ↓
    RTOS
      ↓
Real Embedded Systems
```

I'm starting with the smallest pieces and trying to understand them properly before moving to the next level.

**Jarvis taught me C.**

**FRIDAY is teaching me firmware.** 🚀