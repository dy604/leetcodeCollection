
//题目177，Nth Highest Salary 第N高薪水
//题目176，Second Highest Salary

//在给定的Employee表中查询第N高的薪水
//1、
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N = N - 1;
    RETURN (
        SELECT DISTINCT Salary FROM Employee GROUP BY Salary
        ORDER BY Salary DESC LIMIT 1 OFFSET N
    );
END

//2、
CREATE FUNCTION getNthHighestSalary(N INT) RETURN INT
BEGIN
    RETURN (
        SELECT MAX(Salary) FROM Employee E1
        WHERE N - 1 =
        (SELECT COUNT(DISTINCT(E2.Salary)) FROM Employee E2
         WHERE E2.Salary > E1.Salary)
    );
END

//3、
CREATE FUNCTION getNthHighestSalary(N INT) RETURN INT
BEGIN
    RETURN (
        SELECT MAX(Salary) FROM Employee E1
        WHERE N =
        (SELECT COUNT(DISTINCT(E2.Salary)) FROM Employee E2
         WHERE E2.Salary >= E1.Salary)
    );
END
