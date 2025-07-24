// galaxyGenerator.js
// Shared logic for generating star positions

function generateGalaxy({
  starCount = 10000,
  armCount = 4,
  radius = 1000,
  spinFactor = 1,
  randomness = 0.2
} = {}) {
  const stars = [];
  for (let i = 0; i < starCount; i++) {
    const arm = i % armCount;
    const branchAngle = (arm / armCount) * Math.PI * 2;
    const distance = Math.random() ** 0.5 * radius;
    const angle = distance * spinFactor;

    const offsetX = (Math.random() * 2 - 1) * randomness * radius;
    const offsetY = (Math.random() * 2 - 1) * randomness * radius * 0.1;
    const offsetZ = (Math.random() * 2 - 1) * randomness * radius;

    const x = Math.cos(branchAngle + angle) * distance + offsetX;
    const y = offsetY;
    const z = Math.sin(branchAngle + angle) * distance + offsetZ;

    stars.push({ id: i, x, y, z, color: "#ffffff", arm });
  }
  return stars;
}

if (typeof module !== 'undefined') {
  module.exports = generateGalaxy;
}
