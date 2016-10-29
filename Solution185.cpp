
//题目185，Department Top Three Salaries 系里前三高薪水

//1、
SELECT d.Name AS Department, e.Name AS Employe, e.Salary FROM Employee e
JOIN Department d ON e.DepartmentId = d.Id
WHERE (SELECT COUNT(DISTINCT Salary) FROM Employee WHERE Salary > e.Salary
AND DepartmentId = d.Id) < 3 ORDER BY d.Name, e.Salary DESC;

//2、
SELECT d.Name AS Department, e.Name AS Employee, e.Salary FROM Employee e, Department d
WHERE (SELECT COUNT(DISTINCT Salary) FROM Employee WHERE Salary > e.Salary
AND DepartmentId = d.Id) IN (0, 1, 2) AND e.DepartmentId = d.Id ORDER BY d.Name, e.Salary DESC;

//3、
SELECT d.Name AS Department, e.Name AS Employee, e.Salary FROM
(SELECT e1.Salary, e1.DepartmentId FROM Employee e1 JOIN Employee e2
ON e1.DepartmentId = e2.DepartmentId AND e1.Salary <= e2.Salary GROUP BY e1.Id
HAVING COUNT (DISTINCT e2.Salary) <= 3) e JOIN Department d ON e.DepartmentId = d.Id
ORDER BY d.Name, e.Salary DESC;

//4、
SELECT d.Name AS Department, e.Name AS Employee, e.Salary FROM
(SELECT NAME, Salary, DepartmentId,
@rank := IF(@pre_d = DepartmentId, @rank + (@pre_s <> Salary), 1) AS rank,
@pre_d := DepartmentId, @pre_s := Salary
FROM Employee, (SELECT @pre_d := -1, @pre_s := -1, @rank := 1) AS init
ORDER BY DepartmentId, Salary DESC) e JOIN Department d ON e.DepartmentId = d.Id
WHERE e.rank <= 3 ORDER BY d.Name, e.Salary DESC;
