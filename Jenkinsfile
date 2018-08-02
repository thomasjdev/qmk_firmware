pipeline {
  agent {
    dockerfile {
      filename 'Dockerfile'
    }
  }
  stages {
      stage('Build Planck') {
          steps {
              sh 'make planck/rev4:tj-anderson'
          }
      }
      stage('Build Ergodox') {
          steps {
              sh 'make ergodox_ez:tj-anderson'
          }
      }
  }

  post {
      always {
          archiveArtifacts artifacts: '*.hex', fingerprint: true
      }
  }
}
