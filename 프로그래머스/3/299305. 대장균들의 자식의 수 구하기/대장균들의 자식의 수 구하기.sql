select e.ID, count(ep.ID) as CHILD_COUNT
from ECOLI_DATA as e
left join ECOLI_DATA as ep on e.ID = ep.PARENT_ID
group by e.ID
order by e.ID asc;