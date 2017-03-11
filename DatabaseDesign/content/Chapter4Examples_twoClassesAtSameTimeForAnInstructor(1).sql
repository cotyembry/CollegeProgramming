select t.ID, t.semester, t.year, t.course_id, time_slot_id from teaches as t natural join section as s
where 1 < some (select count(time_slot_id) from section as s1 natural join teaches t2
where t2.ID = t.ID and t2.semester = t.semester 
and t2.year = t.year and s.time_slot_id = s1.time_slot_id);

