
//题目176，Second Highest Salary 第二高薪水
//题目177，Nth Highest Salary

//从Employee表中查第二高的薪水
//1、
SELECT Salary FROM Employee GROUP BY Salary UNION ALL
(SELECT NULL AS Salary)
ORDER BY Salary DESC LIMIT 1 OFFSET 1;

//2、
SELECT MAX(Salary) FROM Employee
WHERE Salary NOT IN
(SELECT MAX(Salary) FROM Employee);

//3、
SELECT MAX(Salary) FROM Employee
WHERE Salary <
(SELECT MAX(Salary) FROM Employee);

//4、
SELECT MAX(Salary) FROM Employee
E1 WHERE 1 =
(SELECT COUNT(DISTINCT(E2.Salary)) FROM Employee E2
 WHERE E2.Salary > E1.Salary);
