import discord
from discord.ext import commands
from colorama import Fore
from dotenv import load_dotenv
import os

# Load variables from .env file
load_dotenv()
CHANNEL_ID = int(os.getenv('CHANNEL_ID'))
API_KEY = str(os.getenv('API_KEY'))
FLAG0 = str(os.getenv('FLAG0'))
FLAG1 = str(os.getenv('FLAG1'))
FLAG2 = str(os.getenv('FLAG2'))
FLAG3 = str(os.getenv('FLAG3'))

# set up intents and authorization
intents = discord.Intents.default()
intents.members = True
intents.message_content = True

# set up bot
bot = commands.Bot(command_prefix='>', intents=intents)
# remove default help command
bot.remove_command('help')

# print when bot is online
@bot.event
async def on_ready():
  print(Fore.GREEN + '*Bot Online')

# new command help
@bot.command()
async def help(ctx):
  embed = discord.Embed(
    title='__Help__',
    description="Section d'aide pour l'**Ascension**",
    color=discord.Color.blue()
  )
  embed.add_field(
    name='>help',
    value='> Tu sais ce que ça fait **:)**',
    inline=False
  )
  embed.add_field(
    name='>send _Epreuve-(n°)_ flag{_answer_}',
    value="> **Envoie et vérifie** ta réponse de l'épreuve spécifié (remplace _(n°)_ par ton épreuve actuel et remplace _answer_ par la réponse de l'épreuve que tu as trouvé)\n\t\t**Marche que dans le salon 'Vérificationis'**",
    inline=False
  )
  await ctx.send(embed=embed)

# command to send the answer
@bot.command()
async def send(ctx, step, answer):
  if ctx.channel.id == CHANNEL_ID:
    error = False
    
    # parse the number of the epreuve
    num = step.split('-')[1]
    user = ctx.message.guild.get_member(ctx.message.author.id)
    
    if num == '0':
      if answer == FLAG0:
        await ctx.message.author.send(f"Bonne réponse **{ctx.author}**, tu vas pouvoir commencer ton ascension... j'espère\n")
        role = ctx.guild.get_role(1184786130172915752)
      else:
        error = True
    
    elif num == '1':
      if answer == FLAG1:
        await ctx.message.author.send(f"Bonne réponse **{ctx.author}**, tu vas pouvoir commencer ton ascension... vraiment cette fois-ci !\n")
        role = ctx.guild.get_role(1184976323773468682)
      else:
        error = True
    
    elif num == '2':
      if answer == FLAG2:
        await ctx.message.author.send(f"Bonne réponse **{ctx.author}**, la première étape est derière toi.\n")
        role = ctx.guild.get_role(1185244577683214387)
      else:
        error = True
    
    elif num == '3':
      if answer == FLAG3:
        await ctx.message.author.send(f"Bonne réponse **{ctx.author}**. Une série enflammée !\n")
        role = ctx.guild.get_role(1186272042572578847)
      else:
        error = True
    
    else: error = True
    
    if error:
      await ctx.message.delete()
      await ctx.message.author.send(f'Hum.. mauvaise réponse **{ctx.author}**, réessaye')
    else:
      await giverolefromadmin1185151809187233823(ctx,user=user,role=role)
      await ctx.message.delete()
  else:
    await ctx.message.delete()


# command to receive the correction
@bot.command()
async def give(ctx, epr):
  if ctx.channel.id == CHANNEL_ID:
    error = False
    
    # parse the number of the epreuve
    num = epr.split('-')[1]
    user = ctx.message.guild.get_member(ctx.message.author.id)
    
    if num == '0':
      await ctx.message.author.send('La correction !', file=discord.File("correction/epreuve0-correction.cpp"))
    
    elif num == '1':
      # Verify you have the right role
      role = discord.utils.get(ctx.guild.roles, name="[novice]")
      if role in user.roles:
        await ctx.message.author.send('La correction ! Le message codé était en encodé en base64, vous pouviez le décoder avec Python ou du C++...\n Mais il existe aussi des décodeurs en ligne.\n Regardez du coté de CyberChef ou decryptpassword :)')
      else:
        error = True
    
    elif num == '2':
      role = discord.utils.get(ctx.guild.roles, name="[débutant]")
      if role in user.roles:
        await ctx.message.author.send('La correction !', file=discord.File("correction/epreuve2-correction.cpp"))
      else:
        error = True
    
    elif num == '3':
      role = discord.utils.get(ctx.guild.roles, name="[apprenti]")
      if role in user.roles:
        await ctx.message.author.send('La correction !', file=discord.File("correction/epreuve3-correction.cpp"))
      else:
        error = True
    
    else: error = True
    
    if error:
      await ctx.message.delete()
      await ctx.message.author.send(f"Une erreur c'est produite /!\ Vous n'avez peut-être pas un grade suffisant.")
    else:
      await ctx.message.delete()
  else:
    await ctx.message.delete()

@bot.command(pass_context=True)
async def giverolefromadmin1185151809187233823(ctx, user: discord.Member, role: discord.Role):
    await user.add_roles(role)
    await ctx.message.author.send(f"Tu as fait une ascension ! **{user.name}**, tu es devenu {role.name}")
    
bot.run(API_KEY)