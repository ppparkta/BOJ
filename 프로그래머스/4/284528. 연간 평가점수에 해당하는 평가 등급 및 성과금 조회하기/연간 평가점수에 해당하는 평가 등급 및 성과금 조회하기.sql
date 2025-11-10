-- 코드를 작성해주세요
select ee.emp_no, ee.emp_name, eee.grade, 
    case
        when eee.grade = 'S' then ee.sal * 0.2
        when eee.grade = 'A' then ee.sal * 0.15
        when eee.grade = 'B' then ee.sal * 0.1
        else 0
    end as bonus
from HR_EMPLOYEES ee join (select  e.emp_no,
      case 
        when avg(g.score)  >= 96 then 'S'
        when avg(g.score)  >= 90 then 'A'
        when avg(g.score)  >= 80 then 'B'
        else 'C'
      end as grade
from HR_GRADE g join HR_EMPLOYEES e on g.emp_no = e.emp_no
group by g.emp_no) as eee on ee.emp_no = eee.emp_no;
