pipeline {
    agent {
        docker { dockerfile }
    }
    stages {
        stage('Test') {
            steps {
                sh 'echo Hello World'
            }
        }
    }
}
