using static System.Convert;
using static SplashKitSDK.SplashKit;

String title;
int saveAmount, havingAmount, savableAmount, targetAmount;
int remainingWeeks;

Write("What are you saving for? Enter title: ");
title = ReadLine();

Write("How much do you need to save? Enter dollars: ");
saveAmount = ToInt32(ReadLine());

Write("How long before the purchase? Enter weeks: ");
remainingWeeks = ToInt32(ReadLine());

Write("How much do you have already? Enter dollars: ");
havingAmount = ToInt32(ReadLine());

Write("how much you can save each week? Enter dollars: ");
savableAmount = ToInt32(ReadLine());

targetAmount = (saveAmount - havingAmount) / remainingWeeks;

WriteLine($"For the {title}, you need to save {targetAmount} dollars a week");
WriteLine($"Based on current saving you will need {saveAmount / savableAmount} weeks to save ${saveAmount}");