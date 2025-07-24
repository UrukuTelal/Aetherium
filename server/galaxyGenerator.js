// galaxyGenerator.js
// Shared logic for generating star positions with metadata, halo, dark matter, and SMBH

function generateGalaxy({
  starCount = 10000,
  armCount = 4,
  radius = 1000,
  spinFactor = 1,
  randomness = 0.2,
  haloFraction = 0.1,
  darkMatterShells = 10,
  includeVelocity = true
} = {}) {
  const stars = [];
  const haloCount = Math.floor(starCount * haloFraction);
  const coreStars = starCount - haloCount;
  const armColors = ["#ffaa88", "#88ccff", "#ffccff", "#ffffaa"];

  // Spiral arms
  for (let i = 0; i < coreStars; i++) {
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

    const size = 0.5 + Math.random() * 2;
    const color = armColors[arm % armColors.length];

    let vx = 0, vy = 0, vz = 0;
    if (includeVelocity) {
      // Basic tangential velocity estimate (orthogonal to radius)
      const speed = Math.sqrt(distance) * 0.02;
      vx = -Math.sin(branchAngle + angle) * speed;
      vy = 0;
      vz = Math.cos(branchAngle + angle) * speed;
    }

    stars.push({ id: i, x, y, z, vx, vy, vz, color, size, arm, cluster: "arm" });
  }

  // Halo
  for (let i = 0; i < haloCount; i++) {
    const distance = radius + Math.random() * radius * 2;
    const theta = Math.random() * Math.PI * 2;
    const phi = Math.acos(2 * Math.random() - 1);
    const x = distance * Math.sin(phi) * Math.cos(theta);
    const y = distance * Math.sin(phi) * Math.sin(theta);
    const z = distance * Math.cos(phi);
    const size = 0.4 + Math.random() * 1.2;

    stars.push({
      id: coreStars + i,
      x, y, z,
      vx: 0, vy: 0, vz: 0,
      color: "#888888",
      size,
      arm: null,
      cluster: "halo"
    });
  }

  // SMBH
  const smbh = {
    mass: 1e9,
    position: { x: 0, y: 0, z: 0 }
  };

  // Dark matter (radial shells)
  const darkMatter = [];
  for (let i = 0; i < darkMatterShells; i++) {
    const inner = (i / darkMatterShells) * radius * 2;
    const outer = ((i + 1) / darkMatterShells) * radius * 2;
    const density = Math.exp(-i * 0.5);
    darkMatter.push({ shell: i, inner, outer, density });
  }

  return { stars, smbh, darkMatter };
}

if (typeof module !== 'undefined') {
  module.exports = generateGalaxy;
}
