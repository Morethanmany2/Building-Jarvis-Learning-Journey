---
title: "Building My First Logic-Based Project in C: A Library Management System"
datePublished: 2026-07-27T17:02:09.871Z
cuid: cms3h5meq00000ajo1bcn6qdj
slug: building-my-first-logic-based-project-in-c-a-library-management-system
cover: https://cdn.hashnode.com/uploads/covers/6a2649aba310674fdac6fca6/e4dd43c6-ce8f-4a87-b7f4-5049fba181c5.jpg
tags: cpp, c, programming-blogs, embedded-systems, marvel

---

When I first started learning C programming, my programs were simple—calculators, loops, patterns, and small logic exercises. They helped me understand the syntax, but they didn't feel like *real software*.

This week, I decided to change that.

Instead of solving another programming exercise, I challenged myself to build a **Library Management System** from scratch.

It took me almost **two weeks**.

Not because the program was extremely large, but because I wanted to design the logic myself.

Alongside my internship in Embedded Systems, I would come home after work, spend a few hours writing code, debugging my mistakes, and understanding how software is actually structured. At the same time, I started learning **Git version control**, breaking the project into GitHub Issues and implementing one feature at a time.

The result wasn't just a working program.

It completely changed the way I think while writing code.

## The Goal

Instead of writing everything inside `main()`, I wanted to build the project the way professional software is developed.

Each feature would have its own responsibility.

The project currently supports:

*   Adding books
    
*   Viewing books
    
*   Registering library members
    
*   Generating unique Member IDs
    
*   Validating phone numbers
    
*   Menu-driven navigation
    

Although this is Version 1 of the project, every feature taught me a different programming concept.

## Breaking the Program into Functions

## One of the biggest lessons I learned was that **functions are not just pieces of code—they represent responsibilities.**

Instead of writing one giant `main()`, I divided the program into modules.

```plaintext
void menu(int choice);
void add_book();
void view_book();
void register_member();
void generate_memberid();
int check_phone();
```

Each function performs exactly one task.

*   `menu()` decides which feature to execute.
    
*   `add_book()` stores book information.
    
*   `view_book()` retrieves stored data.
    
*   `register_member()` handles new member registration.
    
*   `generate_memberid()` creates unique IDs.
    
*   `check_phone()` validates user input.
    

Once I started thinking this way, the program became much easier to understand and maintain.

This is also the same design philosophy used in embedded systems, where every module performs one specific job.

## Using Structures to Model Real Objects

This was my first real use of **structures**.

Instead of creating dozens of separate variables, I grouped related data together.

## Book Structure

```plaintext
struct book{
    int book_id;
    char book_name[50];
    char author[50];
    int copies_available;
};
```

Everything related to a book now belongs inside one structure.

Similarly, I created another structure for members.

```plaintext
struct member{
    int member_id;
    char member_name[50];
    char phone[11];
    int issued;
};
```

For the first time, my variables started representing real-world objects instead of random numbers and strings.

## Logic 1: Adding Books

The first feature I implemented was adding books.

The program asks the librarian for:

*   Book ID
    
*   Book Name
    
*   Author Name
    
*   Number of Available Copies
    

```plaintext
void add_book()
{
    printf("Enter the book id: ");
    scanf("%d",&b1.book_id);

    printf("Enter book name: ");
    scanf("%s",b1.book_name);

    printf("Enter author name: ");
    scanf("%s",b1.author);

    printf("Enter available copies: ");
    scanf("%d",&b1.copies_available);

    printf("Book added successfully!\n");
}
```

Although simple, this function taught me how structures can be used to store related information in an organized way.

## Logic 2: Viewing Stored Books

After storing the data, I wanted users to retrieve it using the Book ID.

Instead of printing every stored value directly, I searched for the entered ID.

```plaintext
void view_book()
{
    int book_id;

    printf("Enter the book id: ");
    scanf("%d",&book_id);

    if(book_id == b1.book_id)
    {
        printf("Book Name: %s\n", b1.book_name);
        printf("Author: %s\n", b1.author);
        printf("Copies: %d\n", b1.copies_available);
    }
    else
    {
        printf("Please enter a valid book ID!\n");
    }
}
```

This helped me understand how programs compare user input with stored information.

* * *

## Logic 3: Registering Library Members

The next feature was member registration.

The program collects:

*   Member Name
    
*   Phone Number
    

After validating the phone number, it automatically generates a Member ID.

```plaintext
void register_member()
{
    printf("Enter the name: ");
    scanf("%s", m1.member_name);

    do
    {
        printf("Enter phone number: ");
        scanf("%s", m1.phone);

    }while(!check_phone());

    generate_memberid();

    printf("Registered Member ID: M%06d\n", m1.member_id);
}
```

This feature connected multiple functions together, making the program feel much more realistic.

* * *

## Logic 4: Automatically Generating Member IDs

Initially, I tried generating IDs manually.

Then I realized software should handle this automatically.

So I created a counter.

```plaintext
int nextmemberid = 12345;

void generate_memberid()
{
    m1.member_id = nextmemberid;
    nextmemberid++;
}
```

When displayed:

```plaintext
M012345
M012346
M012347
```

Every new member receives a unique ID automatically.

A small feature, but one that taught me the importance of automation.

* * *

## Logic 5: Validating Phone Numbers

This feature probably taught me the most.

Instead of accepting any input, I wanted the program to reject invalid phone numbers.

The validation checks:

*   Length must be exactly 10 digits.
    
*   Every character must be a digit.
    

```plaintext
int check_phone()
{
    int len = strlen(m1.phone);

    if(len != 10)
    {
        printf("Phone number should contain 10 digits!\n");
        return 0;
    }

    for(int i = 0; i < len; i++)
    {
        if(m1.phone[i] < '0' || m1.phone[i] > '9')
        {
            printf("Phone number should contain digits only!\n");
            return 0;
        }
    }

    return 1;
}
```

This small function introduced me to input validation, character comparison, ASCII values, loops, and string handling—all in one place.

* * *

## What I Learned Beyond C Programming

This project wasn't only about writing code.

It also taught me software engineering habits.

While building it, I started:

*   Breaking the project into GitHub Issues
    
*   Working on one feature at a time
    
*   Using feature branches
    
*   Learning Git version control
    
*   Thinking about acceptance criteria before writing code
    

Instead of asking,

> "How do I finish this program?"

I started asking,

> "What's the next feature I need to complete?"

That small shift made programming much less overwhelming.

* * *

## AI Became My Mentor

Earlier, whenever I got stuck, I would ask AI to solve the problem.

This time, I tried something different.

Instead of asking for code, I asked questions like:

*   Is my logic correct?
    
*   Am I missing any edge cases?
    
*   Why won't this approach work?
    
*   Can you guide me without giving the complete solution?
    

The project took longer.

But I understood every function I wrote.

And I think that's far more valuable.

* * *

## What's Next?

This is only Version 1 of the Library Management System.

The next features I plan to implement include:

*   Multiple book storage
    
*   Book issuing system
    
*   Book return system
    
*   File handling
    
*   Persistent data storage
    
*   Search functionality  
    I'm excited to continue improving it one feature at a time.
    

* * *

## Final Thoughts

## This project wasn't the biggest program I've written.

But it was the first one that made me think like a software engineer instead of someone just learning syntax.

It taught me that writing software isn't about putting everything inside `main()`.

It's about designing responsibilities, building logic, validating inputs, and solving one problem at a time.

As someone learning C for Embedded Systems, I feel this project has given me a much stronger foundation than simply completing another programming exercise.

Every function I wrote wasn't just code.

It was another step toward thinking like an embedded software engineer.

* * *

## 🚀 Learning Log

This week I learned:

*   ✅ Applying structures in a real project
    
*   ✅ Designing modular functions
    
*   ✅ Building a menu-driven application
    
*   ✅ Validating user input
    
*   ✅ Automatically generating IDs
    
*   ✅ Thinking feature-by-feature using GitHub Issues
    
*   ✅ Using AI as a mentor instead of a solution provider
    

**The project isn't finished yet... and that's the exciting part.** Every new feature is another opportunity to learn.