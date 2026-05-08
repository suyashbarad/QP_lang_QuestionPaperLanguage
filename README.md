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
```

# Output:
```
----------------------------------------------
                Question Paper                
----------------------------------------------

Q1. Define velocity (2 marks)

Q2. Find acceleration when u=0, v=20, t=4 (4 marks)

Number of questions: 2
```

# Structure

**QP_Lang**/<br>
`│`<br>
`├── main.cpp        # C++ parser`<br>
`├── sample.qp       # Input file (QP Lang)`<br>
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
