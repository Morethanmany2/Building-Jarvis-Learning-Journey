---
title: "How Jarvis Learned to Remember, Communicate, and Access Memory"
datePublished: 2026-06-19T05:51:06.308Z
cuid: cmqkig9j4000304ktdqai5dw1
slug: how-jarvis-learned-to-remember-communicate-and-access-memory
cover: https://cdn.hashnode.com/uploads/covers/6a2649aba310674fdac6fca6/ae9cf646-2380-4a88-82d5-b84b6bea6761.jpg

---

In my previous articles, I learned about functions, arrays, strings, and loops by imagining how they could help build an intelligent assistant like Jarvis.

This week, I continued that journey by learning about 2D arrays, string functions, and pointers.

At first, these topics looked like ordinary programming concepts. But when I started thinking about how Jarvis would use them, their importance became much easier to understand.

### Giving Jarvis a Tactical Display with 2D Arrays

Imagine Tony Stark is flying through a city and Jarvis is tracking multiple enemy drones.

For every drone, Jarvis needs to store information such as:

*   X Position
    
*   Y Position
    
*   Threat Level
    

This information can be organized in rows and columns, just like a table.

This is where 2D arrays become useful.

A 2D array allows us to store data in a grid format.

For example:

```plaintext
int enemies[5][3];
```

Here, each row could represent a drone, and each column could represent information about that drone.

Thinking about 2D arrays this way helped me understand how they can be used to organize large amounts of related data.

### Helping Jarvis Understand Commands with Strings

One thing that makes Jarvis special is its ability to communicate with Tony Stark.

When Tony says:

"Jarvis, scan the building."

the system must understand the command before it can perform the action.

In C programming, text is stored using strings.

For example:

```plaintext
char command[] = "scan the building";
```

This week, I also learned several string functions that make working with text easier.

Some useful string functions are:

*   strlen() – Finds the length of a string
    
*   strcpy() – Copies one string into another
    
*   strcmp() – Compares two strings
    
*   strcat() – Combines two strings
    

These functions allow programs to process and manage text efficiently.

If Jarvis receives hundreds of commands every day, string functions would play an important role in understanding and handling them.

### Teaching Jarvis Where Information Lives with Pointers

Pointers were one of the most interesting topics I learned this week.

Until now, Jarvis knew what information existed.

With pointers, Jarvis learns where that information is stored.

A pointer stores the memory address of another variable.

For example:

```plaintext
int battery = 90;
int *ptr = &battery;
```

Here:

*   battery stores the value 90
    
*   ptr stores the address of battery
    

Instead of only knowing the battery level, Jarvis now knows where that battery information is located in memory.

This direct access to memory is one of the reasons C is widely used in embedded systems.

As I learn more about microcontrollers in the coming weeks, I expect pointers to become even more important.

### My Key Takeaway

This week helped me understand that programming is not only about writing code.

It is also about organizing information, processing data, and managing memory efficiently.

Through 2D arrays, Jarvis learned how to organize information in a structured way.

Through strings and string functions, Jarvis learned how to understand and work with text-based commands.

Through pointers, Jarvis learned how to directly access information stored in memory.

Each new topic feels like adding another capability to an intelligent system.

The more I learn, the more I realize that advanced technologies such as AI assistants, robots, and autonomous systems are built using these simple building blocks.

This weekend, Jarvis learned how to organize information, communicate using text, and access memory.

I wonder what new abilities he will gain next weekend.

### Jarvis Capability Log

✓ Store data using variables

✓ Perform calculations

✓ Make decisions

✓ Repeat tasks using loops

✓ Organize abilities using functions

✓ Store collections of information using arrays

✓ Process text using strings

✓ Analyze data using nested loops

✓ Organize data using 2D arrays

✓ Understand text using string functions

✓ Access memory using pointers

🚀 Next Upgrade: Coming Soon