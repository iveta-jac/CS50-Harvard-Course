-- List the names of all people who starred in a movie released in 2004, ordered by birth year
-- If a person appeared in more than one movie in 2004, they should only appear in your results once

SELECT name FROM people WHERE id IN
(SELECT person_id FROM stars WHERE movie_id IN
(SELECT id FROM movies WHERE year = 2004))
ORDER BY birth;


/* Other solutions:

SELECT name FROM people 
JOIN stars ON people.id = stars.person_id 
JOIN movies ON stars.movie_id = movies.id 
WHERE year = 2004 
GROUP BY person_id 
ORDER BY birth;

SELECT name FROM 
(SELECT DISTINCT(people.id), name FROM people 
JOIN stars ON people.id = stars.person_id 
JOIN movies ON stars.movie_id = movies.id 
WHERE year = 2004 
ORDER BY birth);

*/
