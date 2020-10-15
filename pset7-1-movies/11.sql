-- List the titles of the 5 highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated

SELECT title FROM movies 
JOIN ratings ON movies.id = ratings.movie_id WHERE id IN 
(SELECT movie_id FROM stars WHERE person_id IN 
(SELECT id FROM people WHERE name = "Chadwick Boseman")) 
ORDER BY rating DESC LIMIT 5;

 
/* Other solutions:

SELECT title FROM movies 
JOIN stars ON movies.id = stars.movie_id 
JOIN ratings ON stars.movie_id = ratings.movie_id 
JOIN people ON stars.person_id = people.id 
WHERE name = "Chadwick Boseman" 
ORDER BY rating DESC LIMIT 5;
 
*/