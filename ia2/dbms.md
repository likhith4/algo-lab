### 1. Explain informal design guidelines for relation schema with examples 
- There are four informal guidelines that may be used as measures to determine the quality of relation schema design
    1. Making sure that the semantics of the attributes is clear in the schema.
        - Example: consider a schema for an employee database:
        - Good design: ``` Employee(EmployeeID,Name,Birthdate,DeptID); Department:(DepartmentID, DepartmentName,ManagerID)```
        - Poor Design: ```(EmployeeID,Name,BirthDate,DeptID,DepartmentName, ManagerID)```
    2. Reducing the redundant information in tuples.
        - Example: In a poorly designed schema , if each employee record includes the department details then
        - Redundant schema :```(EmployeeID,Name,Birthdate,DeptID,DeptName)``` if a department name changes, it must be updateed in every employee record risking inconsistency. Instead, seperating the Employee and Department tables avoids this redundancy and the associated normalies.
    3. Reducing the NULL values in tuples.:schemas should be designed to minimize NULL values, which can complicate data interpretation and lead to wasted storage.
        - Example: if a schema includes optional atributes that frequently contain NULL values, it may be better to create a seperate reltion for those attributes if phone number is often unknown , consider seperate schema
        ```
            Employee: (EmployeeID, Name, Birthdate, Address)
            Contactinfo:(EmployeeId,PhNo)
        ``` 
        This seperation reduces the number of NULLS in the table.
    4. Disallowing the possibility of generating spurious tuples: a schema should be designed to avoid generating spurious tuples when relations are joined. this can be acheived by ensuring that attributes used for joining are appropriately related , typically through primary and foregin keys;
    - Example:
        - Poor Design: if two tables are joined on non-primary key attributes that are not related, it may produce spurious tuples.
        - Good Design: Ensure joins are made on primary key and foregin key pairs

### 2. Explain functional dependencies with examples 
- A functional dependency is a constraint that specifies a relationship between two sets of attributes in a relation. It is denoted as X--->Y, where:
    - X is a set of attributes known as the determinant
    - Y is a set of attributes known as the dependent.
- The notation signifies that the value of X uniquely determines the value of Y. In other words , for each value of X, there is a exactly one corresponding value of Y.
- Example:
``` 
    | StudentID | StudentName | Class |
    |-------- | --- | --- |
    | 101 | Ajay | 10A |
    | 102 | Bob | 10B |
    | 103 | Charan | 10C |
```
- In this table we can express the following functional dependency:
    - Functional Dependency StudentID--->StudentName this means that knowing the student id allows us to uniquely determine the student name.
### 3. Define normalisation of relations and explain first normal form and second normal form
- Normalizatin of Relations: is the process of orgainizing data in a database to reduce reduncy and improve data integrity. It involves breaking down a database into smaller tables and defining ralationships between them. the goal is to crate a well-structured database that minimizes data duplication and ensures data consistency.
    - First Normal Form (1NF):
        - A relation is first Normal form if it satisfies the following condition:
        1. The relation contains only atomic values. In other words each cell in the table should contain a single value, and there should be no repeating groups or arrays.
        2. The relation has no duplicate rows. Each row in the table should beu unique and distingueshable from other rows.
        3. All columns are defined with the same data type: The data type of each column should be consistent throughout the table.
    - To normalise a relation to 1NF. you need to eliminate any repeating groups or arrays by creating seperate tables for each group and defining relationships between then using primary and foregin keys.
    - Example: Consider the following relation that is not in 1NF:
        StudentID	Name	Courses
        101	Alice	C1, C2
        102	Bob	C3
        103	Carol	C2, C3
    - To normalize this relation to 1NF, we need to create a separate table for courses and define a relationship between students and courses using a junction table: Student
    ```
        StudentID	Name
        101	Alice
        102	Bob
        103	Carol
    ```

    Course:
    ```
        CourseID CourseName
        C1        Course 1
        C2        Course 2
        C3        Course 3
    ```
    Student Course:
    ```
        StudentID  Course ID
        101         C1
        102         C2
        103         C2
        103         C3
    ```

    - Second Normal Form (2NF)
    - A relation is 2NF if it satisfies the following conditions:
    1. The relation is in first normal form.
    2. Every non prime attribute is fully functionally dependent on the primary key. in other words the non key attribute should depend on the entire primary key , not just a part of it 
    - Example
    ```
        Example: Consider the following relation that is in 1NF but not in 2NF:
        OrderID	ProductID	Quantity	Price	Amount
        1001	P101	        10	    5.99	59.90
        1001	P102	        5	    9.99	49.95
        1002	P101	        3	    5.99	17.97
        1002	P103	        2	    7.99	15.98
    ```
    - in this relation the amount attribute is partially dependent on the primary key Order Id and product id as it can be calculated from quantity and price . to normalize this relation to 2NF. we can create  a seperate table for order details.
    ```
        Order
            OrderID	OrderDate
            1001	2023-05-01
            1002	2023-05-02
        
        OrderDetail
            OrderID	ProductID	Quantity	Price
            1001	P101	    10	        5.99
            1001	P102	    5	        9.99
            1002	P101	    3	        5.99
            1002	P103	    2	        7.99

        Product
            ProductID	ProductName	UnitPrice
            P101	Product 1	    5.99
            P102	Product 2	    9.99
            P103	Product 3	    7.99

    ```
    - by breaking down the  original relation into smaller table and defining relationships between them we have eliminated them, we have eliminated partial dependencies and achieved 2NF.

### 4. Explain transitive dependency and mulitvalue dependency
- Transitive Dependency: occurs when a non-prime attributes (an attribute that is not a part of any candidate key) depends on another non-prime  attribute , which in turn depends on candidate key. this creates an indirect relationship where the first non-prime indirectly dependent on the candidate key through the second non-prime attribute
    - Example
    ```
        StudentID	StudentName	Department	HeadOfDepartment
        101	        Alice	        CS	    Dr. Smith
        102	        Bob	            EC	    Dr. Johnson
        103	        Carol	        CS	    Dr. Smith

        Here studentid-->studentname-->dept-->hod
    ```
- Multivaluaed Dependency: occurs when one attribute in a relation can determine multiple valueso f another attribute, independent of other attributes. This type of dependency indicates that for a single value of one attribute , there can be multiple values of another attribute.
    -Example:
    ```
        StudentID	Course	        Hobby
        101	        Math	        Reading
        101	        Math	        Painting
        101	        Science	        Reading
        102	        English	        Sports
        102	        English	        Music

        here multivalued dependencies are : studentid --> course and studentid-->hobby.
    ```

### 5. Differentiate between joint dependency and fifth normal form
- Join Dependecy :
    1. a condition where a relation can be decomposed into multiple relations and original can be reconstructed through joins.
    2. Address the ability to reconstruct original data from decomposed relations.
    3. Not a normalization from itself but a concept used in determining normalization
    4. Requires  understanding of how relations can be joined.
    5. Example : consider a table that contains the information about sales agents , products and companies. if a sales agent can sell multiple products from multiple companies, the relation can be decomposed into seperate talbes for agents, products and and companies, whie still allowing for original relation to be reconstructed through joins.
- Fifth Normal Form (5NF)
    1. a normalization form where every join dependency is implied by the candidate keys ensuring no redundancy.
    2. focuses on eliminating redundancy caused by join dependencies.
    3. A specific level of normalization beyond 4NF.
    4. requires that all join dependencies are accounted for by candidate keys.
    5. Example: conside a table with attributes for travelling salesman , brand , product type . if the relationship between these attributes is such that a travelling salesman can sell multiple brands and product types independently , the table may need to be decomposed into seperate tables for each attribute to satisfy 5NF. this ensure that the join of these tables will reconstruct the original data without introductin redundancy.
### 6. Explain CREATE command with example.
```
    CREATE TABLE table_name (
    column1 datatype,
    column2 datatype,
    column3 datatype,
    ...
    );
```
```
    CREATE TABLE Students (
    StudentID INT PRIMARY KEY,
    Name VARCHAR(50),
    Age INT,
    Address TEXT,
    Phone VARCHAR(15)
);

```
### 7. Explain exists and unique functions in SQL.
- In SQL, the `EXISTS` and `UNIQUE` functions serve different purposes in querying and managing data. Below is an explanation of each, along with examples to illustrate their use.

## EXISTS

The `EXISTS` operator is used in SQL to check for the existence of rows returned by a subquery. It returns `TRUE` if the subquery returns at least one row, otherwise, it returns `FALSE`. This operator is commonly used in the `WHERE` clause to filter records based on the presence of related data in another table.

### Syntax
```sql
SELECT column_name(s)
FROM table_name
WHERE EXISTS (subquery);
```

### Example
Suppose we have two tables: `Customers` and `Orders`. We want to find all customers who have placed at least one order.

```sql
SELECT CustomerName
FROM Customers c
WHERE EXISTS (
    SELECT *
    FROM Orders o
    WHERE o.CustomerID = c.CustomerID
);
```

In this example:
- The outer query selects `CustomerName` from the `Customers` table.
- The subquery checks if there are any rows in the `Orders` table where the `CustomerID` matches that of the customer being evaluated in the outer query.
- If the subquery finds any matching rows, the `EXISTS` condition is `TRUE`, and the customer is included in the results.

## UNIQUE

The `UNIQUE` constraint in SQL is used to ensure that all values in a column are different from one another. It prevents duplicate entries in the specified column(s) of a table. Unlike `EXISTS`, which is used in queries, `UNIQUE` is a constraint applied when creating or altering a table.

### Syntax
```sql
CREATE TABLE table_name (
    column1 datatype UNIQUE,
    column2 datatype,
    ...
);
```

### Example
Let's create a table `Employees` where the `Email` column must be unique.

```sql
CREATE TABLE Employees (
    EmployeeID INT PRIMARY KEY,
    Name VARCHAR(50),
    Email VARCHAR(100) UNIQUE,
    Department VARCHAR(50)
);
```

In this example:
- The `Employees` table is created with an `Email` column that has a `UNIQUE` constraint.
- This means that no two employees can have the same email address. If an attempt is made to insert a duplicate email, the database will raise an error.

## Key Differences

| Aspect       | EXISTS                                      | UNIQUE                                      |
|--------------|---------------------------------------------|---------------------------------------------|
| **Purpose**  | Checks for the existence of rows in a subquery. | Ensures all values in a column are unique. |
| **Usage**    | Used in queries to filter results.         | Used as a constraint during table creation.|
| **Return Type** | Returns `TRUE` or `FALSE`.               | Does not return values; enforces data integrity. |
| **Context**  | Used in `SELECT`, `UPDATE`, or `DELETE` statements. | Applied when defining table structures.    |

In summary, `EXISTS` is a logical operator used in SQL queries to check for the presence of related data, while `UNIQUE` is a constraint that ensures data integrity by preventing duplicate values in a specified column. Understanding both is essential for effective database design and querying.

