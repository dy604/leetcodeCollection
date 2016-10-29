
//题目184，Department Highest Salary 系里最高薪水

//Employee表和Department表，让我们找系里面薪水最高的人的
//1、
SELECT d.Name AS Department, e1.name AS Employee, e1.Salary FROM Employee e1
JOIN Department d On e1.DepartmentId = d.Id WHERE Salary IN
(SELECT MAX(Salary) FROM Employee e2 WHERE e1.DepartmentId = e2.DepartmentId);

//2、
SELECT d.Name AS Department, e.Name AS Employee, e.Salary FROM Employee e, Department d
WHERE e.DepartmentId = d.Id AND e.Salary = (SELECT MAX(Salary) FROM Employee e2 WHERE
e2.DepartmentId = d.Id);

//3、
SELECT d.Name AS Department, e.Name AS Employee, e.Salary FROM Employee e, Department d
WHERE e.DepartmentId = d.Id AND e.Salary >= ALL (SELECT Salary FROM Employee e2 WHERE
e2.DepartmentId = d.Id);
