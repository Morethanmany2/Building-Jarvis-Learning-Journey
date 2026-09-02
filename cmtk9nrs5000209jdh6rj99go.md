---
title: "FRIDAY: My First Register-Level STM32 Interrupt + PWM Project"
datePublished: 2026-09-02T15:44:07.026Z
cuid: cmtk9nrs5000209jdh6rj99go
slug: friday-my-first-register-level-stm32-interrupt-pwm-project
cover: https://cdn.hashnode.com/uploads/covers/6a2649aba310674fdac6fca6/7ef2ec1f-f1b6-4b43-8bc1-ba23c596e182.png

---

After spending time learning C, working with Arduino, and gradually understanding how microcontrollers actually work, I decided it was time to move deeper into embedded systems.

I wanted to stop treating the microcontroller like a black box.

I wanted to know:

**What is actually happening inside the MCU when I configure a GPIO, start a timer, or press a button?**

So I started working with the **STM32F103C8T6 Blue Pill**.

And this project became my first real attempt at controlling hardware using **register-level Embedded C**.

## 🤖 From JARVIS to FRIDAY

If you've followed my previous learning journey, you might remember that I used **JARVIS** as a metaphor for my early embedded/C learning.

But in the MCU world, every chapter eventually has an ending.

**Ultron happened.**

JARVIS was gone.

And now...

### **FRIDAY is online.**

But this time, FRIDAY isn't here to tell me *what code to write.*

The goal is different:

> **Understand why the hardware behaves the way it does.**

Instead of hiding behind high-level libraries, I wanted to interact directly with the STM32 peripherals through their registers.

That meant learning about:

```plaintext
RCC

GPIO

AFIO

TIM2

PWM

EXTI

NVIC

Interrupt Service Routines
```

And, more importantly, understanding **how these peripherals communicate with each other.**

## 🎯 The Project

The objective was simple:

### **Control LED brightness using a push button.**

But instead of using:

```cpp
analogWrite();
```

or a library-based interrupt function, I wanted the STM32 hardware to handle the entire process.

The final architecture looked like this:

```cpp
                BUTTON
                   │
                   ▼
                 PB12
                   │
                   ▼
                EXTI12
                   │
                   ▼
                 NVIC
                   │
                   ▼
                  ISR
                   │
                   ▼
            Change CCR1
                   │
                   ▼
              TIM2 PWM
                   │
                   ▼
                 PA0
                   │
                   ▼
                  LED
```

The button generates the event.

The interrupt tells the CPU about it.

The ISR changes the PWM duty cycle.

And the timer hardware takes care of generating the PWM waveform.

## 🔌 Hardware Used

For this experiment, I used:

*   **STM32F103C8T6 Blue Pill**
    
*   LED
    
*   Current-limiting resistor
    
*   Push button
    
*   ST-Link
    
*   Breadboard and jumper wires
    

The important pins were:

| Pin | Function |
| --- | --- |
| PA0 | TIM2\_CH1 PWM OUTPUT |
| PB12 | Push Button/EXTI12 |

### 1️⃣ First Problem: The GPIO Doesn't Just Exist

Coming from Arduino, I was used to doing something like:

```cpp
pinMode(); digitalWrite();
```

STM32 made me think differently.

Before configuring GPIOA or GPIOB, I first needed to enable their peripheral clocks.

So:

```cpp
RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
```

And because I would be using the Alternate Function / EXTI configuration:

```cpp
RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
```

For TIM2:

```cpp
RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; 
```

### 🧠 FRIDAY's first lesson

The registers aren't random magic numbers.

The clock-control register is essentially saying:

“Turn this peripheral on so I can configure and use it.”

That was one of my first major mindset shifts.

## 2️⃣ Configuring PA0 for PWM

PA0 would be connected to:

```cpp
TIM2_CH1
```

So instead of configuring it as a normal GPIO output, I needed to configure it for **Alternate Function Push-Pull**.

```cpp
GPIOA->CRL &= ~(0xFU << 0);
GPIOA->CRL |=  (0xBU << 0);
```

This was another important realization.

PA0 isn't just:

> “a pin.”

It can be connected internally to different peripherals.

In this case:

```plaintext
PA0
 │
 └── TIM2_CH1
```

So the timer can control the physical output.

## 3️⃣ Configuring the Button

The button was connected to **PB12**.

PB12 needed to work as an input with a pull-up.

```cpp
GPIOB->CRH &= ~(0xFU << 16);
GPIOB->CRH |=  (0x8U << 16);

GPIOB->ODR |= (1U << 12);
```

The button was configured so that pressing it would generate a **falling edge**.

This is where things became more interesting.

I wasn't going to continuously check:

```cpp
if(button_pressed)
```

inside `main()`.

Instead, I wanted the hardware to tell the CPU:

> **“Hey. The button was pressed.”**

That meant using an interrupt.

## ⚙️ 4️⃣ Understanding TIM2 PWM

Now came the fun part.

I wanted the LED brightness to be controlled using PWM.

The STM32 clock configuration for this experiment resulted in an **8 MHz TIM2 clock**.

I configured:

```cpp
TIM2->PSC = 7;
TIM2->ARR = 999;
TIM2->CCR1 = 999;
```

But why these values?

Let's break it down.

### Prescaler

The timer receives:

```plaintext
8 MHz
```

With:

```cpp
PSC = 7;
```

the timer counter frequency becomes:

```cpp
8 MHz / (7 + 1)
= 1 MHz
```

So the timer now increments every:

```cpp
1 µs
```

Then:

```cpp
ARR = 999;
```

gives:

```cpp
1 MHz / (999 + 1)
= 1 kHz
```

So my final PWM frequency is:

### **1 kHz**

That was the moment when a number like `999` stopped looking arbitrary.

It had a reason.

## 🎚️ 5️⃣ Controlling Duty Cycle

The actual brightness is controlled using:

```cpp
TIM2->CCR1
```

I created different brightness levels:

```cpp
const uint16_t brightness_levels[5] =
{
    999,
    750,
    500,
    250,
    0
};
```

Which represent approximately:

```cpp
999 → Full-scale
750 → 75%
500 → 50%
250 → 25%
0   → 0%
```

So instead of creating PWM manually, I let **TIM2 generate it in hardware**.

The CPU only needs to change `CCR1`.

That's it.

## ⚡ 6️⃣ Configuring PWM Mode

TIM2 Channel 1 needs to be configured for PWM Mode 1.

```cpp
TIM2->CCMR1 &= ~(0xFU << 0);
TIM2->CCMR1 |= (6U << 4) | (1U << 3);
```

Here:

```cpp
OC1M = 110
```

selects PWM Mode 1.

And:

```cpp
OC1PE = 1
```

enables the output compare preload.

Then I enabled the channel and configured the polarity:

```cpp
TIM2->CCER |= (1U << 0) | (1U << 1);
```

The polarity was important because of the way my LED was electrically connected.

## ▶️ 7️⃣ Starting the Timer

Before starting the timer, I generated an update event:

```cpp
TIM2->EGR = (1U << 0);
```

Then:

```cpp
TIM2->CR1 |= (1U << 0) | (1U << 7);
```

This enabled:

Auto-reload preload Counter

At this point:

```plaintext
TIM2 
 ↓ 
PWM
 ↓ 
PA0 
 ↓ 
LED
```

The LED was now being controlled by hardware PWM.

## 🚨 8️⃣ Now Comes the Interrupt

The button is on:

`PB12`

But I needed to tell STM32:

`PB12` should be connected to `EXTI12`.

That's where `AFIO` comes in.

```cpp
AFIO->EXTICR[3] &= ~(0xFU << 0); AFIO->EXTICR[3] |= (0x1U << 0);
```

This maps:

`EXTI12 → GPIOB`

So now the hardware knows that the source for EXTI12 is PB12.

## 🔔 9️⃣ Enable `EXTI12`

Next, I enabled the interrupt mask:

```cpp
EXTI->IMR |= (1U << 12);
```

Then configured falling-edge detection:

```cpp
EXTI->FTSR |= (1U << 12);
```

Now the hardware chain became:

```cpp
PB12 
  ↓ 
Falling edge 
  ↓ 
EXTI12
```

But we're not done yet.

The interrupt still needs to reach the CPU.

## 🧠 🔟 Enter NVIC

This is where the Nested Vectored Interrupt Controller comes in.

```cpp
NVIC_EnableIRQ(EXTI15_10_IRQn);
```

Because EXTI lines 10–15 share the same interrupt vector.

So:

```cpp
PB12
 ↓ 
EXTI12
 ↓ 
EXTI15_10
 ↓ 
NVIC 
 ↓ 
CPU
```

And finally...

The CPU can enter the ISR.

## 💥 1️⃣1️⃣ The Interrupt Service Routine

The ISR became the bridge between the button event and the PWM controller.

```cpp
    void EXTI15_10_IRQHandler(void) 
{ 
    if(EXTI->PR & (1U << 12)) 
    {             
        brightness_state++;
        if(brightness_state > 4)
        {
            brightness_state = 0;
        }

        TIM2->CCR1 = brightness_levels[brightness_state];

        EXTI->PR = (1U << 12);
    }
}
```

This small piece of code contains quite a lot of embedded concepts.

## 🔄 The Brightness State Machine

Instead of writing a complicated loop inside the interrupt, I used a simple state variable:

```cpp
volatile uint8_t brightness_state = 0;
```

Every button press increments it:

`brightness_state++;`

Once it reaches the end:

if(brightness\_state > 4) { brightness\_state = 0; }

So the sequence becomes:

```plaintext
   ┌──────────────┐
   │              ▼
100% → 75% → 50% → 25% → 0% 
↑                         │ 
└── ──── ───── ───────────┘
```

And the corresponding PWM value is selected from:

brightness\_levels\[brightness\_state\]

Then:

```cpp
TIM2->CCR1 = brightness_levels[brightness_state];
```

changes the duty cycle.

## 🧹 Why Clear the Pending Bit?

At the end:

```cpp
EXTI->PR = (1U << 12);
```

This clears the pending interrupt flag.

If I don't properly acknowledge the interrupt, the processor can continue seeing the interrupt as pending.

This was another one of those moments where I realized:

> An interrupt isn't just a function that magically runs.

There is an entire hardware mechanism behind it.

## 🤯 The Part That Changed My Thinking

Initially, I thought the program was basically:

```plaintext
Button pressed
     ↓
Change LED brightness
```

But after understanding the peripherals, I realized what was actually happening:

```plaintext
                 STM32
                  │
       ┌──────────┴──────────┐
       │                     │
      PB12                  TIM2
       │                     │
     EXTI12                  │
       │                     │
      NVIC                   │
       │                     │
       ▼                     ▼
      CPU                  PWM
       │                     │
       │                 CCR1 controls
       │                     │
       └─────── ISR ──────────┘
                              │
                              ▼
                             PA0
                              │
                              ▼
                             LED
```

And that's what I was actually trying to learn.

**Not just C syntax.**

Not just STM32 register names.

But how the **hardware architecture fits together**.

## 🚫 Why I Didn't Generate PWM Inside the ISR

This was another important lesson.

I could theoretically try to generate the PWM waveform manually inside software.

But why?

The timer peripheral already exists specifically to do this.

So the CPU does the event handling:

```plaintext
Button pressed
      ↓
Interrupt
      ↓
Change CCR1
      ↓
Exit ISR
```

And the timer independently keeps generating:

```plaintext
PWM → PWM → PWM → PWM → PWM...
```

This is exactly the kind of thinking I want to develop as I move deeper into embedded systems:

> **If hardware can do a repetitive task, let hardware do it.**

## 🧪 What This Project Taught Me

This single project introduced me to several STM32 concepts:

### GPIO

Understanding how pins are configured through registers rather than library functions.

### RCC

Understanding that peripherals need their clocks enabled before they can be used.

### Alternate Functions

Understanding that a GPIO pin can be connected to an internal peripheral such as a timer.

### Timers

Understanding:

```plaintext
PSC
ARR
CCR
```

and how they work together.

### PWM

Understanding how duty cycle can control something physical like LED brightness.

### EXTI

Understanding how GPIO events can become hardware interrupts.

### NVIC

Understanding how interrupts actually reach the CPU.

### ISR

Understanding how software responds to a hardware event.

## ⚠️ The Mistakes Were Part of the Project

This project wasn't a straight line.

I initially had several misconceptions about:

*   EXTI register mapping
    
*   `EXTICR`
    
*   pending interrupt flags
    
*   ISR execution
    
*   GPIO register operations
    
*   PWM polarity
    
*   timer configuration
    

And that's actually what made the project useful.

Because every time something didn't work, I had to ask:

> **Which part of the hardware chain isn't configured correctly?**

Instead of randomly changing code.

That mindset is probably more valuable than the final working program.

## 🧩 Final Working Architecture

The final system can be summarised as:

```plaintext
                 ┌─────────────┐
                 │   BUTTON    │
                 └──────┬──────┘
                        │
                      PB12
                        │
                        ▼
                 ┌─────────────┐
                 │   EXTI12    │
                 └──────┬──────┘
                        │
                        ▼
                 ┌─────────────┐
                 │    NVIC     │
                 └──────┬──────┘
                        │
                        ▼
                 ┌─────────────┐
                 │     ISR     │
                 └──────┬──────┘
                        │
                 brightness_state
                        │
                        ▼
                 ┌─────────────┐
                 │    CCR1     │
                 └──────┬──────┘
                        │
                        ▼
                 ┌─────────────┐
                 │    TIM2     │
                 │     PWM     │
                 └──────┬──────┘
                        │
                      PA0
                        │
                        ▼
                 ┌─────────────┐
                 │     LED     │
                 └─────────────┘
```

# 🦾 FRIDAY Is Online

This project may look simple from the outside:

> **“Press a button → LED brightness changes.”**

But for me, this was much bigger than that.

It was my first serious step toward understanding the STM32 from the **inside out**.

I started with questions like:

> *What does this register do?*

Then moved toward:

> *Why do I need this register?*

And eventually:

> *How do these peripherals work together to produce the behavior I want?*

That is the direction I want to continue exploring.

From GPIO...

to timers...

to interrupts...

to communication protocols...

to drivers...

to RTOS...

and eventually to complete embedded systems.

### **JARVIS may be gone.**

### **But FRIDAY is online.**

And this time, I'm not asking her to write the code for me.

**I'm learning to understand the machine myself.** 🤖⚡