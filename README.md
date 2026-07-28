*This project has been created as part of the 42 curriculum by demane.*

# CPP Module 05

## Description

**CPP Module 05** is about exceptions and a bureaucratic form-signing simulation. The goal is to practice throwing and catching custom exceptions, nested class exceptions, and a small inheritance hierarchy of forms that bureaucrats can sign and execute under grade constraints.

This module contains four exercises:

| Exercise | Focus |
|----------|--------|
| **ex00 — Bureaucrat** | Grades 1–150, increment/decrement, `GradeTooHigh` / `GradeTooLow` |
| **ex01 — Form** | Signable forms with required grades; `beSigned` / `signForm` |
| **ex02 — No, you need form 28B** | Abstract `AForm` + concrete forms (Shrubbery, Robotomy, Presidential) |
| **ex03 — Intern** | Factory that creates forms by name (`makeForm`) |

### Overview

Grades are inverted (1 is highest). Signing and executing check both the bureaucrat’s grade and the form’s state; failures are reported via exceptions or messages as required by the subject.

## Instructions

### Requirements

- A C++ compiler supporting **C++98**
- `make`

### Compilation

```bash
cd ex00   # or ex01 / ex02 / ex03
make
make clean / fclean / re
```

Flags: `-Wall -Wextra -Werror -std=c++98`.

### Execution

```bash
./exec    # ex00–ex03
```

Example themes (ex02):

- `ShrubberyCreationForm` — writes ASCII trees to `<target>_shrubbery`
- `RobotomyRequestForm` — 50% success robotomy message
- `PresidentialPardonForm` — pardon announcement

## Classes & components

| Class | Role |
|-------|------|
| `Bureaucrat` | Immutable name, mutable grade; `signForm` / `executeForm` |
| `Form` / `AForm` | Name, signed flag, sign/exec grades; `beSigned`, `execute` |
| Concrete forms | Target-based actions with their own grade requirements |
| `Intern` | Creates a form from a string name (or returns null / throws on unknown) |

Nested exception types document grade and form errors clearly for callers.

## Resources

### Documentation & references

- [Exceptions](https://en.cppreference.com/w/cpp/language/exceptions)
- [std::exception](https://en.cppreference.com/w/cpp/error/exception)
- [try / catch / throw](https://en.cppreference.com/w/cpp/language/try_catch)
- [fstream](https://en.cppreference.com/w/cpp/io/basic_fstream) — shrubbery output
- 42 subject: *CPP Module 05*

### Use of AI

AI assistance was used for:

- Drafting and formatting this `README.md` according to the 42 curriculum requirements
- Clarifying wording and structuring documentation sections

No AI-generated code was submitted as a substitute for personal implementation. The C++ sources were written and validated by the student.

---

*42 Paris — Common Core*
