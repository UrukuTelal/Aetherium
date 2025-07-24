// generate.js
const fs = require('fs');
const path = require('path');
const generateGalaxy = require('./galaxyGenerator');

const args = process.argv.slice(2);
const opts = {
  starCount: parseInt(args[0]) || 10000,
  armCount: parseInt(args[1]) || 4,
  radius: parseInt(args[2]) || 1000,
};

console.log(`Generating galaxy with ${opts.starCount} stars, ${opts.armCount} arms, radius ${opts.radius}...`);

const stars = generateGalaxy(opts);

const outputPath = path.join(__dirname, 'star_positions.json');
fs.writeFileSync(outputPath, JSON.stringify(stars, null, 2));

console.log(`Saved to ${outputPath}`);
