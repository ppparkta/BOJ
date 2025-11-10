-- 코드를 입력하세요
SELECT ins.name, ins. datetime
from ANIMAL_INS ins
where ins.animal_id not in (
    select outs.animal_id
    from animal_outs outs
)
order by ins.DATETIME
limit 3;