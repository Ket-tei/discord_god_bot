# Architecture

## Stack technique
- **Backend** : FastAPI (Python) pour la logique métier et l'API REST
- **Frontend** : React (JS) pour l'interface de gestion des administrateurs
- **Base de données** : PostgreSQL pour stocker les utilisateurs, rôles, cours et réponses
- **Outils** : Docker pour la conteneurisation, GitHub Actions pour CI/CD

## Rôles des répertoires principaux
- `discord_god_bot/` : Répertoire principal contenant :
  - `backend/` : Code FastAPI avec les routes et gestion des données
  - `frontend/` : Code React avec l'interface d'administration
  - `database/` : Scripts de migration et schéma PostgreSQL
  - `config/` : Fichiers de configuration (JWT, secrets, connexion DB)
  - `deploy/` : Scripts de déploiement (Docker, CI/CD)
  - `docs/ponos/` : Documents fondateurs (objectifs.md, architecture.md, etc.)

## Composants et responsabilités
- **Backend (FastAPI)** :
  - Gère la logique métier (assignation de rôles, validation des réponses)
  - Expose une API REST pour le frontend et les notifications
  - Intègre le système d'authentification (JWT)
- **Frontend (React)** :
  - Interface de gestion des administrateurs (dashboard)
  - Gestion des cours et rôles via un formulaire
  - Affichage des notifications et statistiques
- **Base de données (PostgreSQL)** :
  - Stocke les utilisateurs, rôles, cours, réponses et notifications
  - Relation many-to-many entre utilisateurs et rôles

## Modèle de données principal
```text
Users
- id (PK)
- discord_id (unique)
- role_id (FK à Roles)

Roles
- id (PK)
- name (ex: "étudiant", "formateur")

Courses
- id (PK)
- name
- deadline

Responses
- id (PK)
- user_id (FK à Users)
- course_id (FK à Courses)
- answer (texte)
- status (en attente/validation/rejete)

Notifications
- id (PK)
- user_id (FK à Users)
- message
- timestamp
```

## Flux principaux
1. **Soumission de réponse** :
   - Utilisateur → Frontend → Backend (POST /submit-response)
   - Backend → Sauvegarde réponse dans DB → Envoie notification via Discord

2. **Gestion des rôles** :
   - Administrateur → Frontend → Backend (POST /assign-role)
   - Backend → Met à jour rôle utilisateur dans DB

3. **Validation de réponses** :
   - Administrateur → Frontend → Backend (PUT /validate-response)
   - Backend → Met à jour statut réponse → Envoie notification

## Authentification
- **Discord OAuth2** : Authentification des utilisateurs via le système Discord
- **JWT (JSON Web Token)** : Généré par le backend pour authentifier les requêtes administratives
- **Secrets** : Gérés via le fichier `config/secrets.json` (non commité)

## Configuration
- **Environnements** : Variables d'environnement via `.env` (port, base de données, clé JWT)
- **Docker** : Conteneurs pour backend, frontend et base de données (docker-compose.yml)
- **CI/CD** : GitHub Actions pour tests unitaires, déploiement sur Heroku ou AWS

## Déploiement envisagé
- **Environnements** :
  - Dev : Docker local avec PostgreSQL
  - Prod : Cluster Kubernetes avec PostgreSQL (en cluster) et FastAPI en conteneur
- **Notifications** : Webhook Discord intégré au backend pour envoyer des messages
- **Monitoring** : Logs via Prometheus et Grafana (optionnel)

## Hypothèses
- La structure des cours est fixe et non dynamique (pas de gestion de contenu en temps réel)
- Les notifications sont limitées aux messages Discord (pas de notifications push externes)
- Le système ne gère qu'une seule formation à la fois (pas de multi-formation)
- La base de données est optimisée pour les requêtes de validation de réponses (index sur user_id/course_id)