function findRecipePath(recipes, startItems, targetItem) {
    // Convert recipes into a map for easy lookup
    let recipeMap = new Map();
    for (let recipe of recipes) {
        let [item1, item2, result] = recipe;
        if (!recipeMap.has(item1)) recipeMap.set(item1, {});
        if (!recipeMap.has(item2)) recipeMap.set(item2, {});
        recipeMap.get(item1)[result] = item2;
        recipeMap.get(item2)[result] = item1;
    }

    // BFS
    let queue = startItems.map(item => [item, [item]]);
    let visited = new Set(startItems);
    while (queue.length > 0) {
        let [item, path] = queue.shift();
        if (item === targetItem) return path;
        if (recipeMap.has(item)) {
            for (let result in recipeMap.get(item)) {
                let nextItem = recipeMap.get(item)[result];
                if (!visited.has(nextItem)) {
                    visited.add(nextItem);
                    queue.push([nextItem, [...path, result, nextItem]]);
                }
            }
        }
    }

    return null;
}

const recipes = [
    ["Ash", "Fire", "Charcoal"],
    ["Steam Engine", "Water", "Vapor"],
    ["Brick Oven", "Heat Engine", "Oven"],
    ["Steam Engine", "Swamp", "Sauna"],
    ["Magma", "Mud", "Obsidian"],
    ["Earth", "Mud", "Clay"],
    ["Volcano", "Water", "Volcanic Rock"],
    ["Brick", "Fog", "Cloud"],
    ["Obsidian", "Rain", "Black Rain"],
    ["Colorful Pattern", "Fire", "Rainbow Fire"],
    ["Cloud", "Obsidian", "Storm"],
    ["Ash", "Obsidian", "Volcanic Glass"],
    ["Electricity", "Haze", "Static"],
    ["Fire", "Water", "Steam"],
    ["Dust", "Rainbow", "Powder"],
    ["Computer Chip", "Steam Engine", "Artificial Intelligence"],
    ["Fire", "Mud", "Brick"],
    ["Hot Spring", "Swamp", "Sulfur"],
    ["Adobe", "Graphic Design", "Web Design"],
    ["Colorful Interface", "Data", "Visualization"],
    ["IoT", "Security", "Encryption"],
    ["Colorful Pattern", "Mosaic", "Patterned Design"],
    ["Earth", "Steam Engine", "Excavator"],
    ["Cloud Computing", "Data", "Data Mining"],
    ["Earth", "Water", "Mud"],
    ["Brick", "Fire", "Brick Oven"],
    ["Colorful Pattern", "Obsidian", "Art"],
    ["Rain", "Steam Engine", "Hydropower"],
    ["Colorful Display", "Graphic Design", "Colorful Interface"],
    ["Fire", "Mist", "Fog"],
    ["Exploit", "Web Design", "XSS"],
    ["Computer Chip", "Hot Spring", "Smart Thermostat"],
    ["Earth", "Fire", "Magma"],
    ["Air", "Earth", "Dust"],
    ["Cloud", "Rainbow", "Rainbow Cloud"],
    ["Dust", "Heat Engine", "Sand"],
    ["Obsidian", "Thunderstorm", "Lightning Conductor"],
    ["Cloud", "Rain", "Thunderstorm"],
    ["Adobe", "Cloud", "Software"],
    ["Hot Spring", "Rainbow", "Colorful Steam"],
    ["Dust", "Fire", "Ash"],
    ["Cement", "Swamp", "Marsh"],
    ["Hot Tub", "Mud", "Mud Bath"],
    ["Electricity", "Glass", "Computer Chip"],
    ["Ceramic", "Fire", "Earthenware"],
    ["Haze", "Swamp", "Fog Machine"],
    ["Rain", "Rainbow", "Colorful Display"],
    ["Brick", "Water", "Cement"],
    ["Dust", "Haze", "Sandstorm"],
    ["Ash", "Hot Spring", "Geothermal Energy"],
    ["Ash Rock", "Heat Engine", "Mineral"],
    ["Electricity", "Software", "Program"],
    ["Computer Chip", "Fire", "Data"],
    ["Colorful Pattern", "Swamp", "Algae"],
    ["Fog", "Water", "Rain"],
    ["Rainbow Pool", "Reflection", "Color Spectrum"],
    ["Artificial Intelligence", "Data", "Encryption"],
    ["Internet", "Smart Thermostat", "IoT"],
    ["Cinder", "Heat Engine", "Ash Rock"],
    ["Brick", "Swamp", "Mudbrick"],
    ["Computer Chip", "Volcano", "Data Mining"],
    ["Obsidian", "Water", "Hot Spring"],
    ["Computer Chip", "Thunderstorm", "Power Surge"],
    ["Brick", "Obsidian", "Paving Stone"],
    ["User Input", "Visualization", "Interactive Design"],
    ["Mist", "Mud", "Swamp"],
    ["Geolocation", "Wall", "Map"],
    ["Air", "Rock", "Internet"],
    ["Computer Chip", "Rain", "Email"],
    ["Fire", "Rainbow", "Colorful Flames"],
    ["Hot Spring", "Mineral Spring", "Healing Water"],
    ["Ceramic", "Volcano", "Lava Lamp"],
    ["Brick Oven", "Wall", "Fireplace"],
    ["Glass", "Software", "Vulnerability"],
    ["Fog", "Mud", "Sludge"],
    ["Fire", "Marsh", "S'mores"],
    ["Artificial Intelligence", "Data Mining", "Machine Learning"],
    ["Ash", "Brick", "Brick Kiln"],
    ["Fire", "Obsidian", "Heat Resistant Material"],
    ["Hot Spring", "Sludge", "Steam Engine"],
    ["Artificial Intelligence", "Computer Chip", "Smart Device"],
    ["Fire", "Steam Engine", "Heat Engine"],
    ["Ash", "Earth", "Cinder"],
    ["Rainbow", "Reflection", "Refraction"],
    ["Encryption", "Software", "Cybersecurity"],
    ["Graphic Design", "Mosaic", "Artwork"],
    ["Colorful Display", "Data Mining", "Visualization"],
    ["Hot Spring", "Water", "Mineral Spring"],
    ["Rainbow", "Swamp", "Reflection"],
    ["Air", "Fire", "Smoke"],
    ["Program", "Smart HVAC System", "Smart Thermostat"],
    ["Haze", "Obsidian", "Blackout"],
    ["Brick", "Earth", "Wall"],
    ["Heat Engine", "Steam Locomotive", "Railway Engine"],
    ["Ash", "Thunderstorm", "Volcanic Lightning"],
    ["Mud", "Water", "Silt"],
    ["Colorful Pattern", "Hot Spring", "Rainbow Pool"],
    ["Fire", "Sand", "Glass"],
    ["Art", "Web Design", "Graphic Design"],
    ["Internet", "Machine Learning", "Smart HVAC System"],
    ["Electricity", "Power Surge", "Overload"],
    ["Colorful Pattern", "Computer Chip", "Graphic Design"],
    ["Air", "Water", "Mist"],
    ["Brick Oven", "Cement", "Concrete"],
    ["Artificial Intelligence", "Cloud", "Cloud Computing"],
    ["Computer Chip", "Earth", "Geolocation"],
    ["Color Spectrum", "Graphic Design", "Colorful Interface"],
    ["Internet", "Program", "Web Design"],
    ["Computer Chip", "Overload", "Circuit Failure"],
    ["Data Mining", "Geolocation", "Location Tracking"],
    ["Heat Engine", "Smart Thermostat", "Smart HVAC System"],
    ["Brick", "Mud", "Adobe"],
    ["Cloud", "Dust", "Rainbow"],
    ["Hot Spring", "Obsidian", "Hot Tub"],
    ["Steam Engine", "Volcano", "Geothermal Power Plant"],
    ["Earth", "Fog", "Haze"],
    ["Brick", "Steam Engine", "Steam Locomotive"],
    ["Brick", "Colorful Pattern", "Mosaic"],
    ["Hot Spring", "Steam Engine", "Electricity"],
    ["Ash", "Volcano", "Volcanic Ash"],
    ["Electricity", "Water", "Hydroelectric Power"],
    ["Brick", "Rainbow", "Colorful Pattern"],
    ["Silt", "Volcano", "Lava"],
    ["Computer Chip", "Software", "Program"],
    ["Hot Spring", "Thunderstorm", "Lightning"],
    ["Ash", "Clay", "Ceramic"],
    ["Cybersecurity", "Vulnerability", "Exploit"],
    ["Ash", "Heat Engine", "Ash Residue"],
    ["Internet", "Smart Device", "Cloud Computing"],
    ["Magma", "Mist", "Rock"],
    ["Interactive Design", "Program", "Smart Device"],
    ["Computer Chip", "Electricity", "Software"],
    ["Colorful Pattern", "Graphic Design", "Design Template"],
    ["Fire", "Magma", "Volcano"],
    ["Earth", "Obsidian", "Computer Chip"],
    ["Geolocation", "Location Tracking", "Real-Time Positioning"]
];

let startItems = ["Fire", "Water", "Earth", "Air", "Steam"];
let targetItem = "XSS";

let path = findRecipePath(recipes, startItems, targetItem);
console.log(path);
