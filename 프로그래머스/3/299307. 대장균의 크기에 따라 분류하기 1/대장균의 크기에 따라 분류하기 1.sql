-- 코드를 작성해주세요
select e.id, case
    when e.SIZE_OF_COLONY <= 100
    then 'LOW'
    when e.SIZE_OF_COLONY <= 1000
    then 'MEDIUM'
    else 'HIGH'
end as SIZE
from ecoli_data e;