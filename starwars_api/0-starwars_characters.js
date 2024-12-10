#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];
if (!movieId) {
  console.error('Please provide a movie ID');
  process.exit(1);
}

const apiUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(apiUrl, (error, response, body) => {
  if (error) {
    console.error('Error fetching API:', error);
    return;
  }

  if (response.statusCode !== 200) {
    console.error('Invalid movie ID');
    return;
  }

  const data = JSON.parse(body);
  const characterUrls = data.characters;

  const fetchCharacterName = (url) => {
    return new Promise((resolve, reject) => {
      request(url, (error, response, body) => {
        if (error) {
          reject(error);
        } else {
          const characterData = JSON.parse(body);
          resolve(characterData.name);
        }
      });
    });
  };

  const fetchAllCharacters = async () => {
    try {
      for (const url of characterUrls) {
        const name = await fetchCharacterName(url);
        console.log(name);
      }
    } catch (err) {
      console.error('Error fetching character names:', err);
    }
  };

  fetchAllCharacters();
});
