-- Pattern to remember
-- When a table stores two events of the same process in separate rows, self-join the table to combine them into one row.

-- Examples:
-- start → end
-- login → logout
-- pickup → delivery
-- entry → exit



# Write your MySQL query statement below
select a1.machine_id , ROUND(AVG(a1.timestamp-a2.timestamp),3) as processing_time from Activity a1 join Activity a2 on a1.machine_id=a2.machine_id  and a1.activity_type='end' and a2.activity_type='start'   group by machine_id;