const TelegramBot = require('node-telegram-bot-api');
const express = require('express');
const bodyParser = require('body-parser');
const path = require('path'); 

const TOKEN = "8229226632:AAHq9C0LurhuBANaytMhItsPPcPvnD6UkgU";
const CHAT_ID = "8475231293";

const bot = new TelegramBot(TOKEN, { polling: false });
const app = express();

app.use(bodyParser.json());

// ✅ ADD THIS: serve index.html
app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'index.html'));
});

//const GAS_THRESHOLD = 152;
//let alertSent = false;

/*app.post('/gas', (req, res) => {
  const gasValue = req.body.gas;
  console.log("Gas received:", gasValue); // 👈 DEBUG LINE

  if (gasValue > GAS_THRESHOLD && !alertSent) {
    bot.sendMessage(
      CHAT_ID,
      `⚠ GAS ALERT!\nGas Level: ${gasValue}\nStatus: WARNING!!.. TAKE PRECAUTIONS`
    );
    alertSent = true;
  }

  if (gasValue <= GAS_THRESHOLD) {
    alertSent = false;
  }

  res.send({ status: "ok" });
});*/

let lastLevel = "GOOD";

app.post('/gas', (req, res) => {
  const gasValue = req.body.gas;
  console.log("Gas received:", gasValue);

  let currentLevel = "GOOD";
  let message = "";

  if (gasValue > 300) {
    currentLevel = "TOXIC";
    message = `☠ TOXIC GAS LEVEL!\nGas Level: ${gasValue}\nImmediate Action Required!`;
  } 
  else if (gasValue > 200) {
    currentLevel = "VERY BAD";
    message = `🚨 VERY BAD AIR QUALITY!\nGas Level: ${gasValue}\nPlease ventilate area!`;
  } 
  else if (gasValue > 151) {
    currentLevel = "POOR";
    message = `⚠ POOR AIR QUALITY!\nGas Level: ${gasValue}\nBe cautious!`;
  }

  // Send alert only when level changes
  if (currentLevel !== "GOOD" && currentLevel !== lastLevel) {
    bot.sendMessage(CHAT_ID, message);
  }

  lastLevel = currentLevel;

  res.send({ status: "ok" });
});

app.listen(3000, () => {
  console.log("Server running on http://localhost:3000");
});
