---
title: "Giving Jarvis a Body: Structures, Unions, and My First Embedded Systems Practical"
datePublished: 2026-06-22T09:57:04.356Z
cuid: cmqp1k4wr00030bhz9q2z4fgw
slug: article-4th
cover: https://cdn.hashnode.com/uploads/covers/6a2649aba310674fdac6fca6/7bb85898-eaa4-4274-a4ff-48f3b628fec4.jpg

---

Over the past few weeks, I have been learning the fundamentals of C programming while imagining how each concept could contribute to building an intelligent assistant like Jarvis.

So far, Jarvis has learned how to store information using variables and arrays, organize tasks using functions, process text using strings, and access memory through pointers.

But this week, for the first time, I moved beyond programming concepts and took my first steps into the world of embedded systems. I learned about structures, unions, the 8051 microcontroller, and used Keil uVision and Proteus to perform practical experiments involving LEDs.

Jarvis was finally beginning to interact with the real world.

### Organizing Information with Structures

Imagine Jarvis detects an enemy drone.

To identify and track it, Jarvis needs to store multiple pieces of information:

*   Drone ID
    
*   Drone Name
    
*   Distance
    
*   Threat Level
    

One way to do this would be to create separate variables for everything, but that quickly becomes difficult to manage.

This is where structures become useful.

Structures allow us to group related information together under a single name.

For example, Jarvis could create a profile for every detected object:

```plaintext
struct Drone
{
    int id;
    char name[20];
    float distance;
    int threatLevel;
};
```

Now all the information related to a drone can be stored together.

Thinking about structures this way helped me understand why they are so useful in real applications. They allow programmers to represent real-world objects in software.

### Saving Memory with Unions

While structures help organize information, they also allocate memory for every member.

But what if only one piece of information is needed at a time?

Imagine Jarvis receives data from a sensor.

At one moment the sensor may send a temperature value, at another moment it may send a voltage reading, and at another moment a status code.

Since only one value is active at a time, allocating separate memory for each would be inefficient.

This is where unions become useful.

```plaintext
union SensorData
{
    int temperature;
    float voltage;
    char status;
};
```

Unlike structures, all members of a union share the same memory location.

This allows memory to be used more efficiently, which is especially important in embedded systems where resources are often limited.

For the first time, I started seeing how memory management becomes an important consideration when developing embedded applications.

### Giving Jarvis a Physical Form with the 8051

Up until now, everything I learned existed only in software.

Variables, arrays, strings, pointers, structures, and unions all helped Jarvis think and manage information.

But how does Jarvis interact with the physical world?

This week introduced me to the 8051 microcontroller.

If Jarvis is the brain, then the microcontroller is part of the nervous system that allows software to communicate with hardware.

The 8051 can:

*   Read inputs
    
*   Control outputs
    
*   Monitor sensors
    
*   Execute instructions repeatedly
    

For the first time, I could see how software can directly control electronic devices.

### Learning Keil uVision and Proteus

To work with the 8051, I was introduced to two important tools:

### Keil uVision

Keil is used to write, compile, and debug programs for the microcontroller.

It provides the environment where we create the code that will eventually run on the hardware.

### Proteus

Proteus allows us to simulate circuits and observe how hardware behaves.

Instead of requiring a physical development board, we can test our programs using virtual components and verify whether our logic works correctly.

Using both tools together made it easier to understand the complete development process.

## My First Embedded Systems Practical

One of the most exciting parts of this week's session was controlling LEDs using the 8051.

We performed:

*   LED Blinking
    
*   LED Sourcing
    
*   LED Sinking
    

At first glance, blinking an LED may seem like a simple task.

However, it is often considered the "Hello World" of embedded systems because it demonstrates something very important:

Software can control hardware.

Writing code in Keil and then watching the LED respond in Proteus was the first moment where I truly felt the connection between programming and electronics.

It was a small experiment, but it represented a big milestone in my learning journey.

## Why Functions Became Even More Important

One realization stood out throughout all these practicals.

Functions are incredibly important in embedded systems.

Whether the program needs to:

*   Read sensor data
    
*   Control LEDs
    
*   Process communication
    
*   Monitor system status
    

Functions help divide the program into smaller, reusable modules.

Instead of writing everything inside a single main() function, each task can be organized into its own function.

The more I learn, the more I realize that functions are one of the foundations of scalable and maintainable embedded software.

## Final Thoughts

This week felt like a turning point in my journey.

Structures taught Jarvis how to organize complex information.

Unions showed Jarvis how to use memory efficiently.

The 8051 microcontroller introduced Jarvis to the physical world.

Keil and Proteus helped me understand how software and hardware work together.

And through LED blinking, sourcing, and sinking experiments, I witnessed something I had only imagined before—code controlling electronics.

For the first time, embedded systems stopped being just a topic in a course and started feeling real.

This weekend, Jarvis learned how to organize information, save memory, and interact with hardware.

I wonder what new abilities he will gain next weekend.

## Jarvis Capability Log

✓ Store data using variables

✓ Perform calculations

✓ Make decisions

✓ Repeat tasks using loops

✓ Organize abilities using functions

✓ Store collections of information using arrays

✓ Process text using strings

✓ Analyze data using nested loops

✓ Organize complex data using structures

✓ Optimize memory using unions

✓ Access memory using pointers

✓ Interact with the physical world using a microcontroller

🚀 Next Upgrade: Coming Soon...