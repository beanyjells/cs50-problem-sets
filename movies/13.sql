SELECT DISTINCT name FROM people
JOIN stars ON people.id = stars.person_id
WHERE stars.movie_id IN (
SELECT movies.id FROM movies
JOIN stars ON movies.id = stars.movie_id
WHERE stars.person_id = (
SELECT id FROM people
WHERE name = 'Kevin Bacon' AND birth = 1958))
AND NOT name = 'Kevin Bacon';