# Comprehensive SQL Placement Notes

A detailed guide to SQL (Structured Query Language) based on W3Schools and industry interview standards. This guide covers basic syntax, constraints, joins, advanced functions (Window functions, CTEs), transaction control, database design concepts, and high-frequency placement interview questions.

---

## Table of Contents
1. [Introduction to SQL & Databases](#1-introduction-to-sql--databases)
2. [SQL Data Types](#2-sql-data-types)
3. [SQL Command Categories (DDL, DML, DQL, DCL, TCL)](#3-sql-command-categories)
4. [Basic Querying & Operators](#4-basic-querying--operators)
5. [Data Modification (DML)](#5-data-modification)
6. [Aggregate Functions & Grouping](#6-aggregate-functions--grouping)
7. [Common Built-in Functions](#7-common-built-in-functions)
8. [SQL Joins (Detailed)](#8-sql-joins)
9. [Set Operators](#9-set-operators)
10. [Table & Database Schema Operations (DDL)](#10-table--database-schema-operations)
11. [Constraints](#11-constraints)
12. [Subqueries & Nested Queries](#12-subqueries--nested-queries)
13. [Common Table Expressions (CTEs)](#13-common-table-expressions-ctes)
14. [Window Functions (Crucial for Placements)](#14-window-functions)
15. [Views](#15-views)
16. [Transactions & ACID Properties](#16-transactions--acid-properties)
17. [Indexes & Performance Tuning](#17-indexes--performance-tuning)
18. [Database Normalization](#18-database-normalization)
19. [Top SQL Interview Queries for Placements](#19-top-sql-interview-queries-for-placements)

---

## 1. Introduction to SQL & Databases

### What is SQL?
SQL (Structured Query Language) is the standard language used to communicate with, manage, and manipulate relational databases. 

### RDBMS (Relational Database Management System)
An RDBMS is a database management system based on the relational model introduced by E.F. Codd. In an RDBMS:
* Data is stored in **Tables** (also called relations).
* A table is a collection of related data entries consisting of **Columns** (fields) and **Rows** (records/tuples).
* Popular RDBMS platforms: MySQL, PostgreSQL, MS SQL Server, Oracle, SQLite.

---

## 2. SQL Data Types

Data types define the type of value a column can hold. While specific names vary slightly across RDBMS dialects, the standard SQL types are:

### A. Numeric Types
| Data Type | Description |
| :--- | :--- |
| `INT` / `INTEGER` | Whole numbers (typically 4 bytes). |
| `BIGINT` | Large integers (8 bytes). |
| `SMALLINT` | Small integers (2 bytes). |
| `TINYINT` | Very small integers (1 byte). |
| `DECIMAL(p, s)` / `NUMERIC` | Exact fixed-point decimals. `p` = precision (total digits), `s` = scale (digits after decimal). Example: `DECIMAL(10, 2)` can store up to `99999999.99`. |
| `FLOAT(p)` / `DOUBLE` | Approximate floating-point numbers. |

### B. String / Character Types
| Data Type | Description |
| :--- | :--- |
| `CHAR(n)` | Fixed-length character string. Padded with spaces if shorter than `n`. Max size: 255. |
| `VARCHAR(n)` | Variable-length character string. Does not pad spaces. Max size depends on DB (usually up to 65,535). |
| `TEXT` | Large variable-length character data (up to 2GB or 64KB depending on DB). Used for long descriptions or articles. |

### C. Date and Time Types
| Data Type | Description | Format |
| :--- | :--- | :--- |
| `DATE` | Stores date only. | `YYYY-MM-DD` |
| `TIME` | Stores time only. | `HH:MM:SS` |
| `DATETIME` / `TIMESTAMP` | Stores both date and time. `TIMESTAMP` often adjusts to timezone. | `YYYY-MM-DD HH:MM:SS` |
| `YEAR` | Stores year in 2-digit or 4-digit format. | `YYYY` |

### D. Binary & Other Types
* `BOOLEAN` / `BOOL`: Stores `TRUE` or `FALSE` (often represented as `1` or `0` in MySQL).
* `BLOB` (Binary Large Object): Used for large binary files (images, audio, files).
* `JSON`: Modern databases support native JSON data representation and querying.

---

## 3. SQL Command Categories

SQL commands are grouped into five sub-languages based on their functionality:

```
               ┌────────────────────── SQL Commands ──────────────────────┐
               │                                                          │
      ┌────────┴────────┬────────────────┬────────────────┬───────────────┴────────┐
      ▼                 ▼                ▼                ▼                        ▼
     DDL               DML              DQL              DCL                      TCL
(Data Definition) (Data Manipulation) (Data Query) (Data Control)         (Transaction Control)
  • CREATE          • INSERT         • SELECT        • GRANT                  • COMMIT
  • DROP            • UPDATE                         • REVOKE                 • ROLLBACK
  • ALTER           • DELETE                                                  • SAVEPOINT
  • TRUNCATE
```

1. **DDL (Data Definition Language)**: Defines the database structure or schema.
   * `CREATE`, `DROP`, `ALTER`, `TRUNCATE`.
2. **DML (Data Manipulation Language)**: Modifies the data present inside the database tables.
   * `INSERT`, `UPDATE`, `DELETE`.
3. **DQL (Data Query Language)**: Used to fetch/retrieve data.
   * `SELECT`.
4. **DCL (Data Control Language)**: Controls permissions and access rights.
   * `GRANT`, `REVOKE`.
5. **TCL (Transaction Control Language)**: Manages transactions.
   * `COMMIT`, `ROLLBACK`, `SAVEPOINT`.

---

## 4. Basic Querying & Operators

The fundamental query starts with a `SELECT` statement.

```sql
SELECT column1, column2 FROM table_name;
```

### SELECT DISTINCT
Removes duplicate records from the output.
```sql
SELECT DISTINCT country FROM customers;
```

### WHERE Clause (Filtering)
Filters records based on specified conditions.
```sql
SELECT * FROM employees WHERE salary > 50000;
```

#### Comparison & Logical Operators in WHERE:
* `=`, `<>` (or `!=` for not equal), `>`, `<`, `>=`, `<=`
* `AND`, `OR`, `NOT`
* `BETWEEN val1 AND val2` (inclusive range)
* `IN (val1, val2, ...)` (matches any value in a list)
* `LIKE` (pattern matching using Wildcards)
  * `%` represents zero, one, or multiple characters.
  * `_` represents a single character.
  * Example: `WHERE name LIKE 'A%'` (starts with A); `WHERE name LIKE '%son'` (ends with son); `WHERE name LIKE '_r%'` (has 'r' in the second position).
* `IS NULL` / `IS NOT NULL` (used to check for NULL/empty values).

### ORDER BY (Sorting)
Sorts the result set in ascending (`ASC`) or descending (`DESC`) order. Default is `ASC`.
```sql
SELECT * FROM employees 
ORDER BY department_id ASC, salary DESC;
```

### LIMIT / TOP / OFFSET
Restricts the number of returned rows. Syntax varies by DBMS:
* **MySQL / PostgreSQL**:
  ```sql
  SELECT * FROM employees ORDER BY salary DESC LIMIT 5 OFFSET 2; -- Skips first 2, returns next 5
  ```
* **SQL Server**:
  ```sql
  SELECT TOP 5 * FROM employees ORDER BY salary DESC;
  ```

### Handling NULL Values
NULL represents missing, unknown, or inapplicable values.
* **COALESCE(val1, val2, ...)**: Returns the first non-null value in the list.
  ```sql
  SELECT name, COALESCE(phone, email, 'No Contact Info') AS contact FROM customers;
  ```
* **IFNULL(val, default_val)** (MySQL) / **ISNULL(val, default_val)** (SQL Server) / **NVL(val, default_val)** (Oracle).

### CASE Expression (Conditional Logic)
Equivalent to `if-else` block in programming.
```sql
SELECT name, salary,
       CASE 
           WHEN salary >= 100000 THEN 'High Income'
           WHEN salary BETWEEN 50000 AND 99999 THEN 'Middle Income'
           ELSE 'Low Income'
       END AS income_bracket
FROM employees;
```

---

## 5. Data Modification (DML)

### INSERT INTO
Inserts new rows into a table.
* **Inserting into specific columns**:
  ```sql
  INSERT INTO customers (customer_name, city, country)
  VALUES ('John Doe', 'New York', 'USA');
  ```
* **Inserting multiple rows**:
  ```sql
  INSERT INTO customers (customer_name, city, country)
  VALUES 
  ('Alice Smith', 'London', 'UK'),
  ('Bob Johnson', 'Paris', 'France');
  ```

### UPDATE
Modifies existing records. **Always use a WHERE clause**; otherwise, all records will be updated!
```sql
UPDATE employees 
SET salary = salary * 1.10, status = 'Promoted'
WHERE performance_rating = 'Excellent';
```

### DELETE
Removes records from a table.
```sql
DELETE FROM employees WHERE status = 'Terminated';
```

> [!IMPORTANT]
> **Difference between DELETE, TRUNCATE, and DROP**
> 
> | Feature | DELETE | TRUNCATE | DROP |
> | :--- | :--- | :--- | :--- |
> | **Type** | DML (Data Manipulation) | DDL (Data Definition) | DDL (Data Definition) |
> | **Action** | Deletes specific rows (or all rows if no WHERE is given). | Deletes all rows, resets auto-increment values. | Deletes table schema/structure and all data. |
> | **Speed** | Slower (deletes row by row, generates undo logs). | Faster (deallocates data pages). | Fastest (removes metadata). |
> | **Rollback** | Possible within active transactions. | Not rollback-able in most DBMS (except inside transaction blocks in PostgreSQL/MSSQL). | Not rollback-able. |
> | **Where Clause**| Supported. | Not Supported. | Not Supported. |

---

## 6. Aggregate Functions & Grouping

Aggregate functions perform calculations on a set of values and return a single value.

* `COUNT(column)`: Returns the number of rows.
* `SUM(column)`: Returns the total sum.
* `AVG(column)`: Returns the average.
* `MIN(column)`: Returns the minimum value.
* `MAX(column)`: Returns the maximum value.

> [!NOTE]
> Aggregate functions (except `COUNT(*)`) ignore `NULL` values.

### GROUP BY
Groups rows that have the same values into summary rows (typically used with aggregate functions).
```sql
SELECT department_id, COUNT(*) AS num_employees, AVG(salary) AS avg_salary
FROM employees
GROUP BY department_id;
```

### HAVING Clause
Filters grouped records. **WHERE filters rows before aggregation; HAVING filters groups after aggregation.**
```sql
SELECT department_id, AVG(salary) AS avg_salary
FROM employees
GROUP BY department_id
HAVING AVG(salary) > 60000;
```

#### Order of Execution in SQL Queries (Interview Favorite!):
1. `FROM` (and Joins)
2. `ON` (Join condition filtering)
3. `WHERE` (Row filtering)
4. `GROUP BY` (Grouping)
5. `HAVING` (Group filtering)
6. `SELECT` (Columns projection & expression calculations)
7. `DISTINCT` (Duplicate removal)
8. `ORDER BY` (Sorting)
9. `LIMIT` / `OFFSET` / `TOP` (Row budget/paging)

---

## 7. Common Built-in Functions

SQL provides many built-in functions for performing operations on data. The most common ones tested in placement interviews include:

### A. String Functions
* **`CONCAT(str1, str2, ...)`**: Joins two or more strings together.
  ```sql
  SELECT CONCAT(first_name, ' ', last_name) AS full_name FROM employees;
  ```
* **`CONCAT_WS(separator, str1, str2, ...)`**: "Concatenate With Separator". Joins strings with a designated separator. Skips `NULL` values.
  ```sql
  SELECT CONCAT_WS('-', '2026', '08', '20'); -- Returns '2026-08-20'
  ```
* **`SUBSTRING(str, start, length)`** (or `SUBSTR`): Extracts a substring starting from `start` (1-indexed) with a specified `length`.
  ```sql
  SELECT SUBSTRING(employee_name, 1, 3) FROM employees; -- Returns first 3 characters
  ```
* **`LENGTH(str)`** / **`LEN(str)`**: Returns the length of a string.
  ```sql
  SELECT employee_name, LENGTH(employee_name) FROM employees;
  ```
* **`REPLACE(str, old_str, new_str)`**: Replaces all occurrences of `old_str` with `new_str`.
  ```sql
  SELECT REPLACE(email, '@oldcompany.com', '@newcompany.com') FROM employees;
  ```
* **`UPPER(str)`** & **`LOWER(str)`**: Converts character cases.
  ```sql
  SELECT UPPER(first_name), LOWER(last_name) FROM employees;
  ```
* **`TRIM(str)`**, **`LTRIM(str)`**, **`RTRIM(str)`**: Removes leading and/or trailing spaces.
  ```sql
  SELECT TRIM('  hello world  '); -- 'hello world'
  ```
* **`INSTR(str, substr)`** (MySQL) / **`CHARINDEX(substr, str)`** (SQL Server): Returns the position of the first occurrence of a substring (1-indexed). Returns 0 (or NULL) if not found.
  ```sql
  SELECT INSTR(email, '@') FROM employees; -- Finds position of '@' symbol
  ```
* **`LEFT(str, n)`** & **`RIGHT(str, n)`**: Extracts `n` characters from the left or right side of the string.

### B. Numeric & Math Functions
* **`ABS(x)`**: Returns the absolute (positive) value of `x`.
* **`ROUND(x, decimals)`**: Rounds `x` to a specified number of decimal places.
  ```sql
  SELECT ROUND(123.4567, 2); -- 123.46
  ```
* **`CEILING(x)`** / **`CEIL(x)`**: Returns the smallest integer greater than or equal to `x`.
  ```sql
  SELECT CEILING(25.1); -- 26
  ```
* **`FLOOR(x)`**: Returns the largest integer less than or equal to `x`.
  ```sql
  SELECT FLOOR(25.9); -- 25
  ```
* **`POWER(base, exponent)`**: Raises a number to the power of another.
* **`SQRT(x)`**: Returns the square root of `x`.
* **`MOD(n, m)`** (or `%`): Returns the remainder of `n` divided by `m`.

### C. Date & Time Functions
* **`NOW()`** / **`CURRENT_TIMESTAMP`**: Returns the current date and time.
* **`CURRENT_DATE()`** / **`CURDATE()`**: Returns the current date.
* **`CURRENT_TIME()`** / **`CURTIME()`**: Returns the current time.
* **`DATEDIFF(date1, date2)`**: Returns the difference in days between two dates.
  ```sql
  SELECT DATEDIFF('2026-08-20', '2026-08-10'); -- 10 days
  ```
* **`DATE_ADD(date, INTERVAL expr unit)`** / **`DATE_SUB()`**: Adds/subtracts a time interval to/from a date.
  ```sql
  SELECT DATE_ADD(CURRENT_DATE, INTERVAL 30 DAY);
  ```
* **`EXTRACT(unit FROM date)`**: Extracts a single part (like Year, Month, Day) from a date.
  ```sql
  SELECT EXTRACT(YEAR FROM hire_date) FROM employees;
  ```
* **`YEAR(date)`**, **`MONTH(date)`**, **`DAY(date)`**: Quick helpers to extract year, month, or day (in MySQL).

### D. Date Formatting & Parsing (W3Schools Reference)
* **`DATE_FORMAT(date, format)`** (MySQL): Formats a date value based on the specified format string.
  ```sql
  -- Outputs date like 'Thursday, August 20, 2026'
  SELECT DATE_FORMAT('2026-08-20', '%W, %M %d, %Y');
  ```
  **Common Format Specifiers:**
  * `%Y` - Year as a 4-digit number (e.g., 2026)
  * `%y` - Year as a 2-digit number (e.g., 26)
  * `%m` - Month as a numeric value (01 to 12)
  * `%M` - Month name in full (e.g., August)
  * `%b` - Month name abbreviated (e.g., Aug)
  * `%d` - Day of the month as a numeric value (01 to 31)
  * `%W` - Weekday name in full (e.g., Thursday)
  * `%a` - Weekday name abbreviated (e.g., Thu)
  * `%H` - Hour (00 to 23)
  * `%i` - Minutes (00 to 59)
  * `%s` - Seconds (00 to 59)
* **`STR_TO_DATE(string, format)`** (MySQL): Parses a string to a date/time representation using format specifiers.
  ```sql
  SELECT STR_TO_DATE('20-08-2026', '%d-%m-%Y'); -- Returns date '2026-08-20'
  ```

### E. Advanced & Conversion Functions
* **`CAST(expression AS datatype)`**: Converts a value of one type to another (standard SQL).
  ```sql
  SELECT CAST('2026-08-20' AS DATE);
  SELECT CAST(123.45 AS SIGNED INT); -- Returns 123
  ```
* **`CONVERT(expression, datatype)`**: Similar to `CAST()`, converts values to a different datatype (MySQL/SQL Server).
  ```sql
  SELECT CONVERT('123', SIGNED);
  ```
* **`IF(condition, value_if_true, value_if_false)`** (MySQL): Inline conditional return.
  ```sql
  SELECT name, salary, IF(salary > 80000, 'High', 'Standard') AS salary_tier FROM employees;
  ```
* **`IFNULL(expression, alt_value)`** (MySQL) / **`ISNULL(expression, alt_value)`** (SQL Server): Returns `alt_value` if the expression is `NULL`.
  ```sql
  SELECT name, IFNULL(commission, 0) FROM employees;
  ```
* **`NULLIF(expr1, expr2)`**: Returns `NULL` if `expr1` is equal to `expr2`, otherwise returns `expr1`.
  ```sql
  SELECT NULLIF(10, 10); -- Returns NULL
  SELECT NULLIF(10, 20); -- Returns 10
  ```
* **`COALESCE(val1, val2, ...)`**: Returns the first non-`NULL` value in a list.
  ```sql
  SELECT COALESCE(NULL, NULL, 'First Non-Null', 'Second Non-Null'); -- Returns 'First Non-Null'
  ```

### F. System & Information Functions
* **`DATABASE()`**: Returns the name of the current default database.
* **`USER()`** / **`SYSTEM_USER()`** / **`SESSION_USER()`**: Returns the current user name and host name.
* **`VERSION()`**: Returns the version of the MySQL database server.
* **`CONNECTION_ID()`**: Returns the unique connection ID for the current connection.

---

## 8. SQL Joins

A `JOIN` clause is used to combine rows from two or more tables based on a related column between them.

Let's assume:
* **Table A (Left Table)**: `Employees` (with `department_id`)
* **Table B (Right Table)**: `Departments` (with `department_id`)

```
   Inner Join          Left Join          Right Join          Full Join
     ( A ∩ B )         ( A ∪ (A∩B) )       ( B ∪ (A∩B) )       ( A ∪ B )
       ┌───┐             ┌───┐               ┌───┐               ┌───┐
     ┌─┼─┐ │           ┌─┼─┐ │             ┌─┼─┐ │             ┌─┼─┐ │
     │ └─┼─┘           │ █─┼─┘             │ └─┼─█             │ █─┼─█
     └───┘             └───┘               └───┘               └───┘
```

### 1. INNER JOIN
Returns records that have matching values in both tables.
```sql
SELECT e.employee_name, d.department_name
FROM employees e
INNER JOIN departments d ON e.department_id = d.department_id;
```

### 2. LEFT (OUTER) JOIN
Returns all records from the left table, and the matched records from the right table. If no match is found, NULL is returned for columns in the right table.
```sql
SELECT e.employee_name, d.department_name
FROM employees e
LEFT JOIN departments d ON e.department_id = d.department_id;
```

### 3. RIGHT (OUTER) JOIN
Returns all records from the right table, and the matched records from the left table. If no match is found, NULL is returned for columns in the left table.
```sql
SELECT e.employee_name, d.department_name
FROM employees e
RIGHT JOIN departments d ON e.department_id = d.department_id;
```

### 4. FULL (OUTER) JOIN
Returns all records when there is a match in either left or right table. If no match is found, NULL is filled.
*Note: MySQL does not support FULL JOIN directly. You must simulate it by taking the `UNION` of a `LEFT JOIN` and a `RIGHT JOIN`.*
```sql
SELECT e.employee_name, d.department_name
FROM employees e
FULL OUTER JOIN departments d ON e.department_id = d.department_id;
```

### 5. CROSS JOIN
Returns the Cartesian product of the two tables (combines every row of the left table with every row of the right table). No `ON` clause is used.
```sql
SELECT e.employee_name, d.department_name
FROM employees e
CROSS JOIN departments d;
```

### 6. SELF JOIN
A table is joined with itself. This is useful when comparing rows within the same table (e.g., matching employees to their managers).
```sql
SELECT e1.employee_name AS Employee, e2.employee_name AS Manager
FROM employees e1
INNER JOIN employees e2 ON e1.manager_id = e2.employee_id;
```

---

## 9. Set Operators

Set operators combine the result sets of two or more `SELECT` statements. 

**Rule**: All SELECT statements must have the same number of columns with matching/compatible data types in the same order.

* **UNION**: Combines distinct values from two queries (removes duplicates).
  ```sql
  SELECT city FROM customers
  UNION
  SELECT city FROM suppliers;
  ```
* **UNION ALL**: Combines all values from two queries (retains duplicates). *Faster because it does not perform sorting to remove duplicates.*
* **INTERSECT**: Returns only the common records between two queries.
* **EXCEPT** (or **MINUS**): Returns records from the first query that are not present in the second query.

---

## 10. Table & Database Schema Operations (DDL)

### Database Management
* Create Database: `CREATE DATABASE testDB;`
* Delete Database: `DROP DATABASE testDB;`

### Creating Tables
```sql
CREATE TABLE employees (
    employee_id INT AUTO_INCREMENT,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    email VARCHAR(100) UNIQUE,
    hire_date DATE DEFAULT (CURRENT_DATE),
    salary DECIMAL(10, 2) CHECK (salary > 0),
    department_id INT,
    PRIMARY KEY (employee_id),
    FOREIGN KEY (department_id) REFERENCES departments(department_id)
);
```

### Altering Tables (ALTER TABLE)
Used to add, delete, or modify columns in an existing table.
* **Add Column**:
  ```sql
  ALTER TABLE employees ADD phone_number VARCHAR(15);
  ```
* **Drop Column**:
  ```sql
  ALTER TABLE employees DROP COLUMN phone_number;
  ```
* **Modify Column (Type/Constraints)**:
  * *MySQL*: `ALTER TABLE employees MODIFY COLUMN salary DECIMAL(12, 2);`
  * *SQL Server / PostgreSQL*: `ALTER TABLE employees ALTER COLUMN salary TYPE DECIMAL(12, 2);`

---

## 11. Constraints

Constraints specify rules for data in a table. If a constraint is violated, the transaction fails.

1. **NOT NULL**: Column cannot contain NULL values.
2. **UNIQUE**: Ensures all values in a column are distinct.
3. **PRIMARY KEY**: Uniquely identifies each row in a table. It is a combination of `NOT NULL` and `UNIQUE`. Only one PRIMARY KEY allowed per table.
4. **FOREIGN KEY**: Prevents actions that would destroy links between tables. Links to the `PRIMARY KEY` (or `UNIQUE` key) of another table.
   * **ON DELETE CASCADE**: Automatically deletes referencing records if parent record is deleted.
   * **ON DELETE SET NULL**: Sets foreign key to NULL if parent record is deleted.
5. **CHECK**: Ensures column values satisfy a custom condition.
   ```sql
   ALTER TABLE employees ADD CONSTRAINT chk_salary CHECK (salary >= 20000);
   ```
6. **DEFAULT**: Sets a default value for a column if no value is specified.
7. **CREATE INDEX**: Used to speed up searches/queries.

---

## 12. Subqueries & Nested Queries

A subquery is a query nested inside another SQL statement (`SELECT`, `INSERT`, `UPDATE`, or `DELETE`).

### A. Non-correlated Subquery
Executes independently of the outer query. It runs first and passes results to the outer query.
```sql
-- Find employees who earn more than the average salary
SELECT employee_name, salary 
FROM employees
WHERE salary > (SELECT AVG(salary) FROM employees);
```

### B. Correlated Subquery
Executes by referencing columns of the outer query. It is evaluated once for each row processed by the outer query.
```sql
-- Find employees who earn more than the average salary of their respective departments
SELECT employee_name, salary, department_id
FROM employees e1
WHERE salary > (
    SELECT AVG(salary) 
    FROM employees e2 
    WHERE e2.department_id = e1.department_id
);
```

### C. EXISTS Operator
Checks for the existence of records matching the subquery. Returns `TRUE` if the subquery returns one or more records.
```sql
-- Select suppliers that have products with price > 100
SELECT supplier_name 
FROM suppliers s
WHERE EXISTS (
    SELECT product_name 
    FROM products p 
    WHERE p.supplier_id = s.supplier_id AND p.price > 100
);
```

---

## 13. Common Table Expressions (CTEs)

A CTE is a temporary named result set that you can reference within a `SELECT`, `INSERT`, `UPDATE`, or `DELETE` statement. Defined using the `WITH` keyword.

### Why use CTEs?
* Improves readability of complex nested queries.
* Can be referenced multiple times within a single query.
* Allows writing recursive queries (e.g. organizational chart hierarchies).

### Standard CTE Syntax
```sql
WITH DeptAverage AS (
    SELECT department_id, AVG(salary) AS avg_salary
    FROM employees
    GROUP BY department_id
)
SELECT e.employee_name, e.salary, d.avg_salary
FROM employees e
INNER JOIN DeptAverage d ON e.department_id = d.department_id
WHERE e.salary > d.avg_salary;
```

---

## 14. Window Functions

Window functions perform calculations across a set of table rows that are somehow related to the current row. Unlike aggregate functions, **they do not collapse rows** into a single output row; each row retains its identity.

```sql
SELECT column_name, 
       function_name() OVER (
           PARTITION BY partition_column 
           ORDER BY sort_column
       ) AS window_alias
FROM table_name;
```

### Core Concepts:
* **PARTITION BY**: Splits the rows into partitions (groups). If omitted, the entire table is treated as one partition.
* **ORDER BY**: Defines the logical order of rows within each partition.

### Key Window Functions:

#### 1. RANK() vs DENSE_RANK() vs ROW_NUMBER() (Crucial Interview Topic)
* `ROW_NUMBER()`: Assigns a unique sequential integer to each row starting at 1.
* `RANK()`: Assigns a rank to each row. If there is a tie, rows get the same rank, but the next rank(s) will be **skipped**. (e.g., 1, 2, 2, 4).
* `DENSE_RANK()`: Assigns a rank to each row. If there is a tie, rows get the same rank, and no ranks are **skipped**. (e.g., 1, 2, 2, 3).

**Example Comparison:**
```sql
SELECT employee_name, department_id, salary,
       ROW_NUMBER() OVER (PARTITION BY department_id ORDER BY salary DESC) AS row_num,
       RANK() OVER (PARTITION BY department_id ORDER BY salary DESC) AS rnk,
       DENSE_RANK() OVER (PARTITION BY department_id ORDER BY salary DESC) AS dense_rnk
FROM employees;
```

*Output Simulation for 4 employees with salaries `100k, 90k, 90k, 80k`:*
| Name | Salary | ROW_NUMBER | RANK | DENSE_RANK |
| :--- | :--- | :--- | :--- | :--- |
| John | 100,000 | 1 | 1 | 1 |
| Jane | 90,000 | 2 | 2 | 2 |
| Bob | 90,000 | 3 | 2 | 2 |
| Alice | 80,000 | 4 | 4 | 3 |

#### 2. LAG() and LEAD()
* `LAG(col, offset)`: Accesses data from a previous row in the partition.
* `LEAD(col, offset)`: Accesses data from a subsequent row in the partition.
* Great for finding month-over-month growth or trend differences.
```sql
-- Find difference between current month's sales and previous month's sales
SELECT month, sales,
       LAG(sales, 1) OVER (ORDER BY month) AS prev_sales,
       sales - LAG(sales, 1) OVER (ORDER BY month) AS sales_difference
FROM monthly_sales;
```

#### 3. FIRST_VALUE() and LAST_VALUE()
Returns the first or last value in an ordered set of values.

#### 4. Running Sum / Cumulative Aggregations
```sql
SELECT order_date, order_amount,
       SUM(order_amount) OVER (ORDER BY order_date) AS running_total
FROM orders;
```

---

## 15. Views

A View is a virtual table based on the result-set of an SQL statement. It contains rows and columns just like a real table.
* **Why use Views?**
  * Simplifies complex queries.
  * Enhances security by restricting direct table access (shows only permitted columns).
  * Decouples user-facing views from underlying schema.

```sql
CREATE VIEW ActiveEmployees AS
SELECT employee_id, first_name, last_name, department_id
FROM employees
WHERE status = 'Active';

-- Querying a View
SELECT * FROM ActiveEmployees;

-- Drop View
DROP VIEW ActiveEmployees;
```

---

## 16. Transactions & ACID Properties

A transaction is a single unit of logical work containing one or more SQL statements.

### ACID Properties
1. **Atomicity**: The entire transaction completes successfully, or none of it executes ("All or Nothing").
2. **Consistency**: A transaction takes the database from one valid state to another, preserving integrity constraints.
3. **Isolation**: Concurrent transactions execute independently of each other without interference.
4. **Durability**: Once committed, changes are permanently written to disk and will not be lost even in a system crash.

### Transaction Commands (TCL)
```sql
START TRANSACTION; -- Or BEGIN TRANSACTION

UPDATE accounts SET balance = balance - 500 WHERE account_id = 1;
UPDATE accounts SET balance = balance + 500 WHERE account_id = 2;

-- If everything succeeds:
COMMIT;

-- If a step fails:
ROLLBACK;
```

#### Savepoint
Allows rollback to a specific point inside a transaction.
```sql
START TRANSACTION;
INSERT INTO logs VALUES ('Step 1 Done');
SAVEPOINT sp1;
INSERT INTO logs VALUES ('Step 2 Done');
-- If step 2 failed:
ROLLBACK TO sp1;
COMMIT;
```

### Transaction Isolation Levels (Interview Hot Topic)
To manage concurrency anomalies:
1. **Dirty Read**: Transaction reads uncommitted changes from another transaction.
2. **Non-repeatable Read**: Row read twice yields different data values because another transaction modified and committed.
3. **Phantom Read**: Query run twice returns different sets of rows because another transaction inserted/deleted rows.

| Isolation Level | Dirty Read | Non-repeatable Read | Phantom Read |
| :--- | :---: | :---: | :---: |
| **Read Uncommitted** | Allowed | Allowed | Allowed |
| **Read Committed** | Prevented | Allowed | Allowed |
| **Repeatable Read** | Prevented | Prevented | Allowed (MySQL InnoDB prevents this too) |
| **Serializable** | Prevented | Prevented | Prevented |

---

## 17. Indexes & Performance Tuning

An Index is a database object created on columns to fetch data faster.

### Types of Indexes:
1. **Clustered Index**:
   * Determines the physical order of data in the table.
   * Only **one** clustered index per table (automatically created on the Primary Key).
2. **Non-Clustered Index**:
   * Contains column values paired with a pointer to the actual data location on disk.
   * Multiple non-clustered indexes are allowed.
   ```sql
   CREATE INDEX idx_emp_salary ON employees(salary);
   ```

### SQL Performance Tuning Tips:
* Avoid `SELECT *`. Retrieve only required columns.
* Ensure columns in `JOIN` conditions or `WHERE` clauses are indexed.
* Use `UNION ALL` instead of `UNION` if duplicates are not a concern.
* Avoid wildcard searches with a leading wildcard (e.g. `LIKE '%value'`) as it forces a full table scan instead of using indexes.
* Use `EXISTS` instead of `IN` when dealing with subqueries that yield large datasets.

---

## 18. Database Normalization

Normalization is the process of organizing database tables to minimize redundancy and dependency.

### Normal Forms:
1. **First Normal Form (1NF)**:
   * Each cell contains only **atomic** (indivisible) values.
   * Columns must contain only values of the same data type.
   * Unique column names.
2. **Second Normal Form (2NF)**:
   * Must be in 1NF.
   * All non-key columns must be fully dependent on the entire Primary Key (No partial dependency).
3. **Third Normal Form (3NF)**:
   * Must be in 2NF.
   * No transitive functional dependencies (i.e. non-prime attributes should not determine other non-prime attributes).
4. **Boyce-Codd Normal Form (BCNF)**:
   * A stronger version of 3NF.
   * For every functional dependency `X -> Y`, `X` must be a super key.

---

## 19. Top SQL Interview Queries for Placements

Here are the SQL queries asked in almost every placement interview (FAANG, product-based, service-based companies).

### Q1. Find the 2nd Highest Salary (Without window function and with window function).
* **Approach A: Correlated Subquery (Universal)**
  ```sql
  SELECT MAX(salary) FROM employees
  WHERE salary < (SELECT MAX(salary) FROM employees);
  ```
* **Approach B: Dense Rank (Standard)**
  ```sql
  WITH RankedSalaries AS (
      SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) as rnk
      FROM employees
  )
  SELECT DISTINCT salary FROM RankedSalaries WHERE rnk = 2;
  ```
* **Approach C: LIMIT (MySQL)**
  ```sql
  SELECT DISTINCT salary FROM employees 
  ORDER BY salary DESC 
  LIMIT 1 OFFSET 1;
  ```

### Q2. Find the Nth Highest Salary.
* **Approach A: Correlated Subquery**
  ```sql
  SELECT salary FROM employees e1
  WHERE N - 1 = (
      SELECT COUNT(DISTINCT salary) 
      FROM employees e2 
      WHERE e2.salary > e1.salary
  );
  ```
* **Approach B: CTE & Window Function (Recommended)**
  ```sql
  WITH RankedSalaries AS (
      SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) as rnk
      FROM employees
  )
  SELECT DISTINCT salary FROM RankedSalaries WHERE rnk = :N;
  ```

### Q3. Find Duplicate Records in a Table.
```sql
SELECT email, COUNT(email) 
FROM employees
GROUP BY email
HAVING COUNT(email) > 1;
```

### Q4. Delete Duplicate Records from a Table.
Assuming a table `employees` has duplicates but holds a unique `employee_id`.
* **Approach A: Using Inner Join (MySQL)**
  ```sql
  DELETE e1 FROM employees e1
  INNER JOIN employees e2 ON e1.email = e2.email AND e1.employee_id > e2.employee_id;
  ```
* **Approach B: Using ROW_NUMBER() (PostgreSQL / SQL Server)**
  ```sql
  WITH DuplicateCTE AS (
      SELECT employee_id,
             ROW_NUMBER() OVER (PARTITION BY email ORDER BY employee_id) as rn
      FROM employees
  )
  DELETE FROM employees
  WHERE employee_id IN (SELECT employee_id FROM DuplicateCTE WHERE rn > 1);
  ```

### Q5. Employees Earning More than their Managers (Self Join).
*Table Schema*: `employees(employee_id, employee_name, salary, manager_id)`
```sql
SELECT e.employee_name AS Employee, e.salary AS Emp_Salary, 
       m.employee_name AS Manager, m.salary AS Mgr_Salary
FROM employees e
INNER JOIN employees m ON e.manager_id = m.employee_id
WHERE e.salary > m.salary;
```

### Q6. Department-wise Highest Salary.
*Table Schema*: `employees(employee_id, employee_name, salary, department_id)`
```sql
WITH RankedDeptSalaries AS (
      SELECT employee_name, salary, department_id,
             DENSE_RANK() OVER(PARTITION BY department_id ORDER BY salary DESC) as rnk
      FROM employees
)
SELECT department_id, employee_name, salary 
FROM RankedDeptSalaries 
WHERE rnk = 1;
```

### Q7. Find Active Customers who Bought Product A but NOT Product B.
*Table Schema*: `orders(customer_id, product_name)`
```sql
SELECT DISTINCT customer_id FROM orders WHERE product_name = 'Product A'
EXCEPT
SELECT DISTINCT customer_id FROM orders WHERE product_name = 'Product B';
```
*(If EXCEPT is not supported, use LEFT JOIN or NOT IN)*
```sql
SELECT DISTINCT customer_id 
FROM orders 
WHERE product_name = 'Product A' 
  AND customer_id NOT IN (
      SELECT DISTINCT customer_id FROM orders WHERE product_name = 'Product B'
  );
```

### Q8. Select Odd or Even ID Rows.
* **Even IDs**:
  ```sql
  SELECT * FROM employees WHERE employee_id % 2 = 0;
  ```
* **Odd IDs**:
  ```sql
  SELECT * FROM employees WHERE employee_id % 2 <> 0;
  ```
