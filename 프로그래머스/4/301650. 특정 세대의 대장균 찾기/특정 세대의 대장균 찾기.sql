-- 코드를 작성해주세요
select id
from ecoli_data e
where e.parent_id in (
    select e.id
    from ecoli_data e
    where e.PARENT_ID in (
        select e.id
        from ecoli_data e
        where e.parent_id is null
    )
);