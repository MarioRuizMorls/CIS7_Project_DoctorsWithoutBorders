# CIS7_Project_DoctorsWithoutBorders
README.MD 

General Description:

Case Project: We chose to do the Doctors without Borders case project; our program aims to ask fellow participants in the program Doctors without Borders, which is an organization that allows students to work in distinct medical care humanitarian projects around the world, input-based questions of their preexisting knowledge and expertise. The program takes user input regarding their language fluency, specialty, and country preference. Then, using those parameters, calculates the probability compatibility percentage for each country depending on the user's input and then informs the user of the country with the highest probability of being assigned.

Programming approach: The project was reasonably straightforward, asking the user for their input and then using that input to calculate the probability of matching with a country. The first problem we addressed was how to ask the user for input, ensuring that only quality responses were inputted. We created a function to check the response is acceptable and does not crash the program; if it is not valid, it continues to ask the user for a valid response until provided. Another approach that we had a problem with was the probability algorithm. At first, we did not think of using a weighted system regarding language, specialty, and country for the probability of being assigned to each country. In our first approach, we did the probability based on language and specialty. then, we incorporated country preference, and finally, we added multiple languages and specialties to create more realistic probabilities. 

Published: Dec 10, 2023

Instructions: Inside CIS7-Project file contains the main file for the program. To use our program, you simply run the program, and it will display a catalog of all the countries, languages, and specialties. The program then asks the user questions regarding their preferences and skills, and it calculates your country's probability for all the countries in Doctors without Borders using the user input.

