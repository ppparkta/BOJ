-- 코드를 입력하세요
SELECT nins.name, nins.datetime
from animal_ins as nins
where animal_id not in (
    select ins.animal_id
    from animal_ins as ins
    join animal_outs as outs 
    on ins.animal_id = outs.animal_id)
order by datetime asc
limit 3;