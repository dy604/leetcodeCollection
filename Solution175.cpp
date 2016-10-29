
//题目175，Combine Two Tables 联合两表

//Person表与Address表通过Person表的主键PersonId关联
//1、
SELECT Person.FirstName, Person.LastName, Address.City, Address.State FROM Person
LEFT JOIN Address ON Person.PersonId = Address.PersonID;

//2、
SELECT Person.FirstName, Person.LastName, Address.City, Address.State FROM Person
LEFT JOIN Address USING(PersonId);

//3、
SELECT Person.FirstName, Person.LastName, Address.City, Address.State FROM Person
NATURAL LEFT JOIN Address;
