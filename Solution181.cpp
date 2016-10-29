
//题目181，Employees Earning More Than Their Managers 员工挣得比经理多

//给定Employee表，查找工资比经理高的员工名
//1、
SELECT e1.Name FROM Employee e1
JOIN Employee e2 ON e1.ManagerId = e2.Id
WHERE e1.Salary > e2.Salary;

//2、
SELECT e1.Name FROM Employee e1, Employee e2
WHERE e1.ManagerId = e2.Id AND e1.Salary > e2.Salary;
