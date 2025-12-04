@echo off
echo ================================================
echo   Starting Bulletin Board System - SERVER
echo ================================================
echo.
echo Starting server on port 27000...
echo.

cd server
"TCP WIN server multiClient.exe"

cd ..
pause
