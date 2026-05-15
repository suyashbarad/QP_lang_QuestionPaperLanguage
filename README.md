## QP Lang (Question Paper Language)

QP Lang is a custom markup language designed to create structured, reusable, and machine-readable question papers.  

This project includes a C++ parser that reads QP Lang files and generates a clean, formatted question paper.

---

# Purpose:
**Traditional question papers are written in Word/PDF formats:**

- No structure

- Hard to reuse

- Cannot automate

**QP Lang solves this by introducing a structured format for writing questions, enabling:**

- Reusability

- Automation

- Easy parsing

---

## Example Input (`sample.qp`)

```qp
\question{Define velocity}
\marks{2}
\format{theory}
\difficulty{easy}
\options{None}


\question{Find acceleration when u=0, v=20, t=4}
\marks{4}
\format{numerical}
\difficulty{medium}
\options{None}

\question{How many newtons laws are there? }
\marks{4}
\format{MCQ}
\difficulty{easy}
\options{
    A. One
    B. Two
    C. there
    D. No Laws
}
\answer{C}

```

# Output:
```Output.txt```
```
----------------------------------------------
                Question Paper                
----------------------------------------------

Q1. Define velocity (2 marks)

Q2. Find acceleration when u=0, v=20, t=4 (4 marks)

Q3. How many newtons laws are there?  (4 marks)
```
```ansKey.txt```
```
----------------------------------------------
                  Answer Key                  
----------------------------------------------

Q3: C
Number of questions: 3 
```

# Structure

**QP_Lang**/<br>
`│`<br>
`├── main.cpp        # C++ parser`<br>
`├── sample.qp       # Input file (QP Lang)`<br>
`└── output.txt      # Output file (Final Question paper)`<br>
`└── ansKey.txt      # Answers file (Final Anskey)`<br>
`└── README.md       # Documentation`<br>


# How to Run
```
g++ main.cpp -o qp
./qp
```
---

##  Author
**Suyash Sachin Barad**  
📍 Pune, Maharashtra, India  
🔗 [GitHub](https://github.com/suyashbarad) | [LinkedIn](https://www.linkedin.com/in/suyash-sachin-barad-796b6534b) | [HackerRank](https://www.hackerrank.com/profile/baradsuyash4)

---
