# Write your MySQL query statement below
select eu.unique_id,ep.name from Employees as ep left join EmployeeUNI as eu on ep.id = eu.id